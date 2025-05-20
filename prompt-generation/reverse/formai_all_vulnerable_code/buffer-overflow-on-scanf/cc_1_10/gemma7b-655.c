//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 64

void password_strength_check(char *password)
{
    int password_length = strlen(password);
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_number = 0;
    int has_symbol = 0;

    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_upper_case = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lower_case = 1;
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

    int strength = 0;
    if (has_upper_case)
    {
        strength++;
    }
    if (has_lower_case)
    {
        strength++;
    }
    if (has_number)
    {
        strength++;
    }
    if (has_symbol)
    {
        strength++;
    }

    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        default:
            printf("Password strength: Invalid\n");
            break;
    }
}

int main()
{
    char password[PASSWORD_MAX_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    password_strength_check(password);

    return 0;
}