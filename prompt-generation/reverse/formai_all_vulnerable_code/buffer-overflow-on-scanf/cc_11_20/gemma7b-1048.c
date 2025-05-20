//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 1024

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Password too short, must be at least 8 characters.\n");
        return 1;
    }

    int has_upper = 0;
    int has_lower = 0;
    int has_number = 0;
    int has_symbol = 0;

    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = 1;
        }
        else if (islower(password[i]))
        {
            has_lower = 1;
        }
        else if (isdigit(password[i]))
        {
            has_number = 1;
        }
        else if (ispunct(password[i]))
        {
            has_symbol = 1;
        }
    }

    if (has_upper && has_lower && has_number && has_symbol)
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is not strong.\n");
        return 1;
    }

    return 0;
}