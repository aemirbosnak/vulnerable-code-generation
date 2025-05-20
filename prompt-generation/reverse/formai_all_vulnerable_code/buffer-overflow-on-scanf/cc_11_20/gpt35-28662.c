//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char hex[20];
    long int decimal,remainder,quotient;
    int i=1,j,temp;
    printf("\nEnter any hexadecimal number: ");
    scanf("%s",hex);
    decimal=0;
    for(j=strlen(hex)-1;j>=0;j--)
    {
        if(hex[j]>='0' && hex[j]<='9')
        {
            decimal+=(hex[j]-48)*i;
            i*=16;
        }
        else if(hex[j]>='A' && hex[j]<='F')
        {
            decimal+=(hex[j]-55)*i;
            i*=16;
        }
        else if(hex[j]>='a' && hex[j]<='f')
        {
            decimal+=(hex[j]-87)*i;
            i*=16;
        }
    }
    printf("\nEquivalent decimal number is: %ld",decimal);

    quotient=decimal;
    i=1;
    while(quotient!=0)
    {
         temp=quotient%16;
         if(temp<10)
         {
            temp+=48;
         }
         else
         {
            temp+=55;
         }
         hex[i++]=temp;
         quotient/=16;
    }
    printf("\nEquivalent hexadecimal number is: ");
    for(j=i-1;j>0;j--)
    {
         printf("%c",hex[j]);
    }
    return 0;
}