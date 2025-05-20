//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char pass[50];
    int len,count=0,i,j;
    float strength;
    char ch;

    printf("\nEnter the Password: ");
    scanf("%s",pass);

    len=strlen(pass);

    for(i=0;i<len;i++)
    {
        if(isalpha(pass[i]))
        {
            count++;
        }
        else if(isdigit(pass[i]))
        {
            count++;
        }
        else if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='%' || pass[i]=='^' || pass[i]=='&' || pass[i]=='*')
        {
            count++;
        }
    }

    if(len<8)
    {
        printf("\nPassword is Weak\n");
    }
    else if(count<2)
    {
        printf("\nPassword is Weak\n");
    }
    else if(count>=2 && count<4)
    {
        printf("\nPassword is Medium\n");
    }
    else if(count>=4 && count<6)
    {
        printf("\nPassword is Strong\n");
    }
    else
    {
        printf("\nPassword is Very Strong\n");
    }

    return 0;
}