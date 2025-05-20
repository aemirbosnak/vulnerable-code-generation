//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char password[1000];
    int len, score=0;

    printf("Welcome to Password Strength Checker!\n");
    printf("Enter your password: ");
    scanf("%s", password);

    len = strlen(password);
    
    for(int i=0; i<len; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            score += 10;
        }
        else if(isalpha(password[i]))
        {
            score += 20;
        }
        else if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~'))
        {
            score += 30;
        }
        else
        {
            score += 40;
        }
    }

    if(len >= 8 && len < 13)
    {
        score += 50;
    }
    else if(len >= 13 && len < 20)
    {
        score += 80;
    }
    else if(len >= 20)
    {
        score += 100;
    }

    if(score >= 100)
    {
        printf("Password is EXTREMELY STRONG!\n");
    }
    else if(score >= 80 && score < 100)
    {
        printf("Password is VERY STRONG!\n");
    }
    else if(score >= 60 && score < 80)
    {
        printf("Password is STRONG!\n");
    }
    else if(score >= 40 && score < 60)
    {
        printf("Password is MODERATE!\n");
    }
    else if(score >= 20 && score < 40)
    {
        printf("Password is WEAK!\n");
    }
    else
    {
        printf("Password is EXTREMELY WEAK!\n");
    }

    return 0;
}