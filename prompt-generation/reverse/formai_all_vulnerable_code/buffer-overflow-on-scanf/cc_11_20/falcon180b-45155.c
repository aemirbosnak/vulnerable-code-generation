//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LEN 100

int main()
{
    char password[MAX_LEN];
    int len, i, found_digit = 0, found_lowercase = 0, found_uppercase = 0, found_special = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    len = strlen(password);

    for(i = 0; i < len; i++)
    {
        if(isdigit(password[i]))
        {
            found_digit = 1;
        }
        else if(isalpha(password[i]))
        {
            if(islower(password[i]))
            {
                found_lowercase = 1;
            }
            else if(isupper(password[i]))
            {
                found_uppercase = 1;
            }
        }
        else if(isalnum(password[i]))
        {
            found_special = 1;
        }
    }

    if(len >= 8)
    {
        if(found_digit && found_lowercase && found_uppercase && found_special)
        {
            printf("Password is strong.\n");
        }
        else
        {
            printf("Password is weak.\n");
        }
    }
    else
    {
        printf("Password is too short.\n");
    }

    return 0;
}