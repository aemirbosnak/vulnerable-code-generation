//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Calculate password strength based on the following criteria:
    // - Number of uppercase letters
    // - Number of lowercase letters
    // - Number of digits
    // - Presence of special characters

    if (password_length >= 8)
    {
        strength++;
    }

    if (hasUppercase(password))
    {
        strength++;
    }

    if (hasLowercase(password))
    {
        strength++;
    }

    if (hasDigits(password))
    {
        strength++;
    }

    if (hasSpecialCharacters(password))
    {
        strength++;
    }

    // Display password strength
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

    return 0;
}

int hasUppercase(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            return 1;
        }
    }

    return 0;
}

int hasLowercase(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            return 1;
        }
    }

    return 0;
}

int hasDigits(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            return 1;
        }
    }

    return 0;
}

int hasSpecialCharacters(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            return 1;
        }
    }

    return 0;
}