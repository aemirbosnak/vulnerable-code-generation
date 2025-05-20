//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int length, i;

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    length = strlen(password);

    // Remove trailing newline character
    if (password[length - 1] == '\n')
    {
        password[length - 1] = '\0';
        length--;
    }

    // Check password length
    if (length < 8)
    {
        printf("Weak: Password should be at least 8 characters long.\n");
        return 1;
    }

    // Check for uppercase letters
    int has_uppercase = 0;
    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase)
    {
        printf("Weak: Password should contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for lowercase letters
    int has_lowercase = 0;
    for (i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase)
    {
        printf("Weak: Password should contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for digits
    int has_digits = 0;
    for (i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
        {
            has_digits = 1;
            break;
        }
    }
    if (!has_digits)
    {
        printf("Weak: Password should contain at least one digit.\n");
        return 1;
    }

    // Check for special characters
    int has_special_chars = 0;
    for (i = 0; i < length; i++)
    {
        if (!isalnum(password[i]))
        {
            has_special_chars = 1;
            break;
        }
    }
    if (!has_special_chars)
    {
        printf("Weak: Password should contain at least one special character.\n");
        return 1;
    }

    printf("Strong: Your password is strong.\n");
    return 0;
}