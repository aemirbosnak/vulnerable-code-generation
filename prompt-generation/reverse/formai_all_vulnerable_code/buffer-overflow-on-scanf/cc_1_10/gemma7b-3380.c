//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int validate_password(char *password)
{
    int password_length = strlen(password);
    if (password_length < 8)
    {
        return 0;
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            return 1;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            return 1;
        }
    }

    // Check for numbers
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    if (validate_password(password))
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is not strong. Please use a stronger password.\n");
    }

    return 0;
}