//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[256];
    int password_length;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        strength -= 1;
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
    }

    // Check for numbers
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
    }

    // Check for symbols
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            strength++;
        }
    }

    // Print password strength
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
            printf("Password strength: Very Strong\n");
            break;
    }

    return 0;
}