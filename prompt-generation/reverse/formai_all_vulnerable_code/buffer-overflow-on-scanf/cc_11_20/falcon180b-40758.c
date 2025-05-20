//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    char password[100];
    int length, i, j, uppercase = 0, lowercase = 0, digit = 0, special = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            uppercase = 1;
        }
        else if(islower(password[i]))
        {
            lowercase = 1;
        }
        else if(isdigit(password[i]))
        {
            digit = 1;
        }
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*')
        {
            special = 1;
        }
    }

    if(length < 8)
    {
        printf("Password must be at least 8 characters long.\n");
    }
    else if(uppercase == 0 && lowercase == 0 && digit == 0 && special == 0)
    {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}