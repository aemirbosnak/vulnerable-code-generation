//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, min_length = 10, max_length = 20;
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length || strlen(password) > max_length)
    {
        printf("Error: Password must be between %d and %d characters long.\n", min_length, max_length);
        return 1;
    }

    // Check for lowercase letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;
    }

    // Check for uppercase letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;
    }

    // Check for number
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
            strength++;
    }

    // Check for special character
    for (i = 0; i < strlen(password); i++)
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
            printf("Password strength: Very strong\n");
            break;
    }

    return 0;
}