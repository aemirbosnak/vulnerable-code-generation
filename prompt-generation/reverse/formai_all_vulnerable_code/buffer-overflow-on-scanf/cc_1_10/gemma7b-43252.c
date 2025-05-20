//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
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

    // Check password length
    if (password_length < 8)
    {
        strength -= 10;
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            strength += 20;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
        {
            strength += 20;
        }
    }

    // Check for numbers
    for (int i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
        {
            strength += 10;
        }
    }

    // Check for symbols
    for (int i = 0; i < password_length; i++)
    {
        if (ispunct(password[i]))
        {
            strength += 10;
        }
    }

    // Calculate overall strength
    strength = (strength / 100) * 100;

    // Print strength
    printf("Password strength: %d%%", strength);

    return 0;
}