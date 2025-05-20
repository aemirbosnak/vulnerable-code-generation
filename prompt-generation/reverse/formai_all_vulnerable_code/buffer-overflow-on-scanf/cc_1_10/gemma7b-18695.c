//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 64

int main()
{
    char password[PASSWORD_MAX_LENGTH];
    int password_length;
    int strength;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    strength = calculate_password_strength(password, password_length);

    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Strong\n");
            break;
        case 3:
            printf("Password strength: Very Strong\n");
            break;
    }

    return 0;
}

int calculate_password_strength(char *password, int password_length)
{
    int strength = 0;
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

    if (has_upper_case && has_lower_case && has_numbers && has_symbols)
    {
        strength = 3;
    }
    else if (has_upper_case || has_lower_case || has_numbers || has_symbols)
    {
        strength = 2;
    }
    else
    {
        strength = 0;
    }

    return strength;
}