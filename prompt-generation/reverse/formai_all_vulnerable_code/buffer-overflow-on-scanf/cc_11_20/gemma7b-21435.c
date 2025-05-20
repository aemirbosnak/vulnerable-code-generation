//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        strength++;
    }

    // Check for uppercase letter
    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            strength++;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
        {
            strength++;
        }
    }

    // Check for number
    for (int i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
        {
            strength++;
        }
    }

    // Check for special character
    for (int i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            strength++;
        }
    }

    // Print strength
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