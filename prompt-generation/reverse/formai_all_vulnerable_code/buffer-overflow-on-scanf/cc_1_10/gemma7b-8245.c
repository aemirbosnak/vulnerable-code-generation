//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculate the password length
    password_length = strlen(password);

    // Check if the password meets the strength requirements
    int strength = check_password_strength(password, password_length);

    // Print the password strength
    if (strength == 0)
    {
        printf("Password too weak.\n");
    }
    else if (strength == 1)
    {
        printf("Password acceptable.\n");
    }
    else if (strength == 2)
    {
        printf("Password strong.\n");
    }
    else
    {
        printf("Password too strong.\n");
    }

    return 0;
}

int check_password_strength(char *password, int password_length)
{
    int strength = 0;

    // Check for minimum length
    if (password_length < 8)
    {
        strength--;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength--;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength--;
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength--;
    }

    // Check for special character
    if (!strchr(password, '!'))
    {
        strength--;
    }

    // Check for complexity
    if (strength == 0)
    {
        strength--;
    }

    return strength;
}