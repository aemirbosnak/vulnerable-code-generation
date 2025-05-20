//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char password[30];
    int length, i;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, special = 0;
    for(i=0; i<length; i++)
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
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?' || password[i] == '-' || password[i] == '+' || password[i] == '=' || password[i] == '^' || password[i] == '~')
        {
            special = 1;
        }
    }
    if(length < 8)
    {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    else if(length > 30)
    {
        printf("Password cannot be more than 30 characters long.\n");
        return 0;
    }
    else if(uppercase == 0 && lowercase == 0 && digit == 0 && special == 0)
    {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
        return 0;
    }
    else
    {
        printf("Password is strong enough.\n");
        return 0;
    }
}