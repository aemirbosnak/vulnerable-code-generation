//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MIN_LENGTH 8

int main()
{
    char password[PASSWORD_MIN_LENGTH];
    int password_length;
    int i;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < PASSWORD_MIN_LENGTH)
    {
        printf("Error: Password must be at least %d characters long.\n", PASSWORD_MIN_LENGTH);
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
            strength++;
    }

    // Check for lowercase letter
    for (i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
            strength++;
    }

    // Check for number
    for (i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
            strength++;
    }

    // Check for symbol
    for (i = 0; i < password_length; i++)
    {
        if (ispunct(password[i]))
            strength++;
    }

    // Calculate password strength
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
            printf("Error: Invalid password strength.\n");
            break;
    }

    return 0;
}