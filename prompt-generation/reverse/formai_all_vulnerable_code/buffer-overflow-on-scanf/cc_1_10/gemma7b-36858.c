//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_MIN_LENGTH 8

int main()
{
    char password[PASSWORD_MIN_LENGTH];
    int password_strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < PASSWORD_MIN_LENGTH)
    {
        printf("Error: Password must be at least %d characters long.\n", PASSWORD_MIN_LENGTH);
        return 1;
    }

    // Check for uppercase letter
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL)
    {
        password_strength++;
    }

    // Check for lowercase letter
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL)
    {
        password_strength++;
    }

    // Check for number
    if (strpbrk(password, "0123456789") != NULL)
    {
        password_strength++;
    }

    // Check for special character
    if (strpbrk(password, "!@#$%^&*())_+-={}[]|\\:") != NULL)
    {
        password_strength++;
    }

    // Calculate strength level
    switch (password_strength)
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
    }

    return 0;
}