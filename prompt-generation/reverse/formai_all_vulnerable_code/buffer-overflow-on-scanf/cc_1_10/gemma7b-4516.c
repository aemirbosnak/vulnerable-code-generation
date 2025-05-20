//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[255];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = strength - 10;
    }

    // Check for uppercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            strength = strength + 20;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            strength = strength + 10;
        }
    }

    // Check for numbers
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            strength = strength + 15;
        }
    }

    // Check for symbols
    for (int i = 0; i < strlen(password); i++)
    {
        if (ispunct(password[i]))
        {
            strength = strength + 25;
        }
    }

    // Calculate overall strength
    strength = strength / 100;

    // Display strength
    printf("Password strength: %d/%d\n", strength, 100);

    return 0;
}