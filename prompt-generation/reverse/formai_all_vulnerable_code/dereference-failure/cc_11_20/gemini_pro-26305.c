//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char*s,*w,*dup;
int k,l,n=10,r,I,i,j,W=0,z=0;
long long h,e=1ll;
size_t S=16ll;

int main()
{
  srand(time(0));
  while(n--)
  {
    h=e;
    s=malloc(++S);
    w=malloc(S);
    dup=malloc(S);
    scanf("%[^\n]s",s);
    l=strlen(s);
    h+=(l+5ll)*8ll;
    for(j=0;j<l;++j) {w[j]=(rand()%26)+65;dup[j]=w[j];h+=8ll;}
    for(i=0;i<1000ll-(l+1ll);++i)h++;
    printf("\n");
    for(k=1;k<=h;++k)
    {
      r=rand()%10;
      if(r==0)printf("\r");
      if(r<=1)
      {
        if(l>0){I=rand()%l;w[I]=32;printf("\r%s",w);}
      }
      if(r==2)
      {
        if(l>0){I=rand()%l;w[I]=dup[I];printf("\r%s",w);}
      }
      if(r>=3)printf("\r%s",w);
      printf("\r");
      for(j=0;j<l;++j)putchar(s[j]);
      if(k==(h-1ll))printf("\nYou took %llds to type the above words. \n",h);
      if(strcmp(s,w)==0)
      {
        W++;
        printf("\nCongratulations!! You typed it correct!!");
        printf("\nYou have typed %d words correctly out of 10!!",W);
        if(W==10) printf("\nCongratulations!!! You have done an excellent job!!\n");
        break;
      }
    }
    free(s);
    free(w);
    free(dup);
  }
  return 0;
}