#include <iostream>
#include <cmath>
using namespace std;

class complexCls{
   double r,i;
  public:
   complexCls(int m=0 , int n=0){r=m;i=n;}
   void Show(){cout<<r<<"+ i "<<i<<endl;}
   double Magnitude(){return sqrt(r*r+i*i);}

   complexCls operator += (complexCls &a){
      r += a.r;
      i += a.i;
      return *this;
   }
   complexCls operator -= (complexCls &a){
      r -= a.r;
      i -= a.i;
      return *this;
   }
   complexCls operator *= (complexCls &a){
      r = r * a.r - i * a.i;
      i = i * a.r + r * a.i;
      return *this;
   } // It is not necessary to implement the = operator
   // for this class, because the default behavior of
   // this operator is identical to the following
   // implementation.
   complexCls operator = (const complexCls a){
      r = a.r;
      i = a.i;
      return *this;
   }
   complexCls(const complexCls & a){
      r = a.r;
      i = a.i;
   }
/*   double & operator [] (const int index){
      if(index == 0)  return r;
      if(index == 1)  return i;
      cout<< " Error in accessing the value;\n";
      return r;
   }
*/
   double & operator [] (const int index){
     double &m=r;
      if(index == 0)  m=r;
      if(index == 1)  m=i;
      else{
        cout<< " Error in accessing the value;\n";
        m=r;
      }
      return m;
   }
   double& operator()(int index){
      switch(index){
         case 0:
            return r;
            break;
         case 1:return i;break;
         default:
            cout<<"Error index "<< endl;
            break;
      }
      return r;
   }
            
   friend complexCls operator +(const complexCls  a , const complexCls  b);
   friend complexCls operator -(const complexCls  a , const complexCls  b);
   friend complexCls operator *(const complexCls  a , const complexCls  b);

};
complexCls operator +(const complexCls  a ,const  complexCls  b){
      complexCls result ;
      result.r = a.r + b.r;
      result.i = a.i + b.i;
      return result;
}
complexCls operator -(const complexCls  a , const complexCls  b){
   complexCls result ;
   result.r = a.r - b.r;
   result.i = a.i - b.i;
   return result;
}
complexCls operator *(const complexCls  a , const complexCls  b){
   complexCls result;
   result.r = a.r * b.r - a.i * b.i;
   result.i = a.i * b.r + a.r * b.i;
   return result;
}


int main(){
      complexCls a(2,3);
      complexCls b(4,5);
      complexCls c;
      c = a + b;
      c.Show();
      c = a + 12;
      c.Show();
      c = 12 + a;
      c.Show();
      a[0]=14;
      a[1]=25;
      a.Show();
      cout<<a[0]<<endl;
      a(0)=8;
      complexCls z[5];
      z[0][0]=4;
      z[0][1]=5;
      z[0].show();
      return 0;
}

