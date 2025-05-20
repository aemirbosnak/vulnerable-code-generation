//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_MIN_LENGTH 8

int main()
{
    char password[PASSWORD_MIN_LENGTH];
    int password_strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < PASSWORD_MIN_LENGTH)
    {
        printf("Error: Password is too short.\n");
        return 1;
    }

    // Check for lowercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            password_strength++;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            password_strength++;
        }
    }

    // Check for numbers
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            password_strength++;
        }
    }

    // Check for symbols
    for (int i = 0; i < strlen(password); i++)
    {
        if (!isalnum(password[i]))
        {
            password_strength++;
        }
    }

    // Print password strength
    switch (password_strength)
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
        default:
            printf("Error: Invalid password strength.\n");
            break;
    }

    return 0;
}