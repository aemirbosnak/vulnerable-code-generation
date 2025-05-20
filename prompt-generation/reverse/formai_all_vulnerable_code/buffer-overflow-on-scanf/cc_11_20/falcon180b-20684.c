//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{
    char hex[100],i;
    int dec,len,j;
    printf("Enter a hexadecimal number: ");
    scanf("%s",hex);
    len=strlen(hex);

    for(i=0;i<len;i++)
    {
        if(isalpha(hex[i]))
        {
            if(isupper(hex[i]))
            {
                dec=hex[i]-55;
            }
            else
            {
                dec=hex[i]-48;
            }
        }
        else if(isdigit(hex[i]))
        {
            dec=hex[i]-48;
        }
        else
        {
            printf("Invalid character found!");
            exit(0);
        }
        if(i==0 && dec==0)
        {
            printf("Invalid hexadecimal number!");
            exit(0);
        }
        j=i-1;
        while(j>=0)
        {
            if(hex[j]=='A' || hex[j]=='a' || hex[j]=='B' || hex[j]=='b' || hex[j]=='C' || hex[j]=='c' || hex[j]=='D' || hex[j]=='d' || hex[j]=='E' || hex[j]=='e' || hex[j]=='F' || hex[j]=='f')
            {
                break;
            }
            else
            {
                printf("Invalid hexadecimal number!");
                exit(0);
            }
        }
    }
    printf("Decimal equivalent: %d",dec);
    return 0;
}