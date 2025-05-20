//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 10

int main()
{
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 2:
            printf("Your password is somewhat strong. It meets the minimum requirements, but could be improved.\n");
            break;
        case 3:
            printf("Your password is strong. It meets all of the requirements.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password)
{
    int strength = 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_number = 0;
    int has_symbol = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lower = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_upper = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_number = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbol = 1;
        }
    }

    if (has_upper && has_lower && has_number && has_symbol)
    {
        strength = 3;
    }
    else if (has_upper || has_lower || has_number || has_symbol)
    {
        strength = 2;
    }
    else
    {
        strength = 0;
    }

    return strength;
}