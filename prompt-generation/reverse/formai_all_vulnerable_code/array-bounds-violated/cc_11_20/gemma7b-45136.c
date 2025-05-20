//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWD_LENGTH 100

int main()
{
    char password[MAX_PASSWD_LENGTH];
    int password_length;

    // Get the password from the user
    printf("Enter your password: ");
    fgets(password, MAX_PASSWD_LENGTH, stdin);

    // Remove the newline character from the password
    password_length = strlen(password);
    password[password_length - 1] = '\0';

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the password strength
    switch (strength)
    {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderate.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password)
{
    int length = strlen(password);
    int has_numbers = 0;
    int has_symbols = 0;
    int has_lowercase = 0;
    int has_uppercase = 0;

    // Check for numbers
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            has_numbers = 1;
        }
    }

    // Check for symbols
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbols = 1;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lowercase = 1;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_uppercase = 1;
        }
    }

    // Calculate the password strength
    int strength = 0;
    if (has_numbers) strength++;
    if (has_symbols) strength++;
    if (has_lowercase) strength++;
    if (has_uppercase) strength++;

    return strength;
}