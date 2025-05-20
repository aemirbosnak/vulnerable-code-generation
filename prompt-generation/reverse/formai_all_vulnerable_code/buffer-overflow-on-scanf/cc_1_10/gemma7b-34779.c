//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

void check_password_strength(char *password)
{
    int password_length = strlen(password);
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_numbers = 0;
    int has_symbols = 0;

    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            has_upper_case = 1;
        }
        else if (islower(password[i]))
        {
            has_lower_case = 1;
        }
        else if (isdigit(password[i]))
        {
            has_numbers = 1;
        }
        else if (ispunct(password[i]))
        {
            has_symbols = 1;
        }
    }

    int strength = 0;

    if (has_upper_case && has_lower_case)
    {
        strength++;
    }
    if (has_numbers)
    {
        strength++;
    }
    if (has_symbols)
    {
        strength++;
    }

    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 2:
            printf("Your password is moderate. It is acceptable, but could be stronger.\n");
            break;
        case 3:
            printf("Your password is strong. It has all the necessary criteria.\n");
            break;
    }
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}