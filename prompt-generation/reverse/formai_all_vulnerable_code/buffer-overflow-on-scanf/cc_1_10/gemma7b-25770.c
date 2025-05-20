//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char password[256];
    int password_length;
    int i, j, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for minimum length
    if (password_length < 8)
    {
        printf("Password too short!\n");
        exit(1);
    }

    // Check for uppercase letters
    for (i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
            strength++;
    }

    // Check for lowercase letters
    for (i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
            strength++;
    }

    // Check for numbers
    for (i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
            strength++;
    }

    // Check for symbols
    for (i = 0; i < password_length; i++)
    {
        if (ispunct(password[i]))
            strength++;
    }

    // Calculate strength percentage
    strength = (strength / password_length) * 100;

    // Print strength
    printf("Password strength: %d%%", strength);

    return 0;
}