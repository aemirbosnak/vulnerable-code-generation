//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < min_length)
    {
        printf("Error: Password must be at least %d characters long.\n", min_length);
        return 1;
    }

    // Iterate over password characters
    for (i = 0; password[i] != '\0'; i++)
    {
        // Uppercase letter
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;

        // Lowercase letter
        else if (password[i] >= 'a' && password[i] <= 'z')
            strength++;

        // Number
        else if (password[i] >= '0' && password[i] <= '9')
            strength++;

        // Symbol
        else if (password[i] >= '!' && password[i] <= '~')
            strength++;
    }

    // Calculate password strength
    if (strength >= 3)
        printf("Password strength: Strong\n");
    else if (strength >= 2)
        printf("Password strength: Moderate\n");
    else if (strength >= 1)
        printf("Password strength: Weak\n");
    else
        printf("Password strength: Very Weak\n");

    return 0;
}