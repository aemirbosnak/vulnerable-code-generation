//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8;

    printf("Enter password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length)
    {
        printf("Error: Password too short. Minimum %d characters required.\n", min_length);
        return 1;
    }

    // Iterate over password characters
    for (i = 0; password[i] != '\0'; i++)
    {
        // Check for lowercase letter
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;

        // Check for uppercase letter
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;

        // Check for number
        if (password[i] >= '0' && password[i] <= '9')
            strength++;

        // Check for special character
        if (password[i] >= '!' && password[i] <= '~')
            strength++;
    }

    // Calculate password strength
    if (strength < 3)
    {
        printf("Password strength: Weak\n");
    }
    else if (strength >= 3 && strength < 6)
    {
        printf("Password strength: Moderate\n");
    }
    else if (strength >= 6)
    {
        printf("Password strength: Strong\n");
    }

    return 0;
}