//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char password[100];
    int length, i, upper=0, lower=0, digit=0, special=0;
    int count=0, total=0;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            upper++;
        }
        else if(islower(password[i]))
        {
            lower++;
        }
        else if(isdigit(password[i]))
        {
            digit++;
        }
        else
        {
            special++;
        }
    }

    if(length < 8)
    {
        printf("Password should be at least 8 characters long.\n");
        exit(0);
    }

    if(upper == 0 && lower == 0 && digit == 0 && special == 0)
    {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
        exit(0);
    }

    if(length > 20)
    {
        printf("Password is too long. It should not exceed 20 characters.\n");
        exit(0);
    }

    if(upper == 0 || lower == 0 || digit == 0 || special == 0)
    {
        printf("Password is weak. It must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
        exit(0);
    }

    printf("Password is strong.\n");
    exit(0);
}