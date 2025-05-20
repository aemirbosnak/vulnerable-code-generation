//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[256];
    int password_length;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        strength -= 1;
    }

    // Check for uppercase letter
    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            strength += 1;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
        {
            strength += 1;
        }
    }

    // Check for number
    for (int i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
        {
            strength += 1;
        }
    }

    // Check for special character
    for (int i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            strength += 1;
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
            printf("Password strength: Very Strong\n");
            break;
    }

    return 0;
}