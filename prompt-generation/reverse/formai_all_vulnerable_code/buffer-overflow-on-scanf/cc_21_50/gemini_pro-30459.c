//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: irregular
//Binary Converter
#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,t,n,mini;
    char i,m,j,o,p,q,r,s;
    printf("Hello There, I will convert your decimal to binary numbers : ");
    printf("\nEnter your number : ");
    scanf("%d",&n);
    for(i='0',j='0',o='0',p='0',q='0',r='0',s='0',mini=0,t=64;(t>=1);t/=2)
    {
        if(n>=t)
        {
            n-=t;
            m=i;
            a=j;
            b=o;
            c=p;
            d=q;
            e=r;
            f=s;
            g=mini;
        }
        else
        {
            m='0';
            a='0';
            b='0';
            c='0';
            d='0';
            e='0';
            f='0';
            g++;
        }
        h=n;
        if(h==0)
        {
            if(m!='0'&&a!='0'&&b!='0'&&c!='0'&&d!='0'&&e!='0'&&f!='0')
            {
                printf("\n%c %c %c %c %c %c %c = %d",s,r,q,p,o,j,i,t*g);
            }
            else if(m!='0'&&a!='0'&&b!='0'&&c!='0'&&d!='0'&&e!='0')
            {
                printf("\n0 %c %c %c %c %c %c = %d",s,r,q,p,o,j,i,t*g);
            }
            else if(m!='0'&&a!='0'&&b!='0'&&c!='0'&&d!='0')
            {
                printf("\n0 0 %c %c %c %c %c = %d",s,r,q,p,o,j,i,t*g);
            }
            else if(m!='0'&&a!='0'&&b!='0'&&c!='0')
            {
                printf("\n0 0 0 %c %c %c %c = %d",s,r,q,p,o,j,i,t*g);
            }
            else if(m!='0'&&a!='0'&&b!='0')
            {
                printf("\n0 0 0 0 %c %c %c = %d",s,r,q,p,o,j,i,t*g);
            }
            else if(m!='0'&&a!='0')
            {
                printf("\n0 0 0 0 0 %c %c = %d",s,r,q,p,o,j,i,t*g);
            }
            else if(m!='0')
            {
                printf("\n0 0 0 0 0 0 %c = %d",s,r,q,p,o,j,i,t*g);
            }
            return 0;
        }
        else
        {
            printf("%c",g);
            i=m;
            j=a;
            o=b;
            p=c;
            q=d;
            r=e;
            s=f;
            mini=g;
        }
    }
    printf("\nConversion Complete");
    return 0;
}