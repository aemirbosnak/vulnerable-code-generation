//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8, max_length = 16;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length || strlen(password) > max_length)
    {
        printf("Password must be between %d and %d characters.\n", min_length, max_length);
        return 1;
    }

    // Check for lowercase letters
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;
    }

    // Check for uppercase letters
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;
    }

    // Check for numbers
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
            strength++;
    }

    // Check for symbols
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
            strength++;
    }

    // Calculate password strength
    strength = strength / 4;

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
            printf("Password strength: Strong\n");
            break;
        case 3:
            printf("Password strength: Very Strong\n");
            break;
        default:
            printf("Password strength: Unknown\n");
            break;
    }

    return 0;
}