//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int i,j,k,n,m,count=0;
char str[MAX],temp[MAX];

int main()
{
    printf("Enter the color code: ");
    scanf("%s",str);

    if(strlen(str)!=6 && strlen(str)!=8)
    {
        printf("Invalid color code\n");
        exit(0);
    }

    if(strlen(str)==6)
    {
        for(i=0;i<3;i++)
        {
            if(str[i]<'0' || str[i]>'9')
            {
                printf("Invalid color code\n");
                exit(0);
            }
        }
        for(i=3;i<6;i++)
        {
            if(str[i]<'A' || str[i]>'F')
            {
                printf("Invalid color code\n");
                exit(0);
            }
        }
    }
    else if(strlen(str)==8)
    {
        for(i=0;i<6;i++)
        {
            if(str[i]<'0' || str[i]>'9')
            {
                printf("Invalid color code\n");
                exit(0);
            }
        }
        for(i=6;i<8;i++)
        {
            if(str[i]<'A' || str[i]>'F')
            {
                printf("Invalid color code\n");
                exit(0);
            }
        }
    }

    if(strlen(str)==6)
    {
        printf("RGB color code is: ");
        for(i=0;i<3;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
        printf("Hexadecimal color code is: ");
        for(i=3;i<6;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    else if(strlen(str)==8)
    {
        printf("RGB color code is: ");
        for(i=0;i<6;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
        printf("Hexadecimal color code is: ");
        for(i=6;i<8;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}