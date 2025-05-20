//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[256];
    int password_strength = 0;
    int i = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length of 8 characters
    if (strlen(password) < 8)
    {
        password_strength = -1;
    }

    // Check for uppercase letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            password_strength++;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            password_strength++;
        }
    }

    // Check for number
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            password_strength++;
        }
    }

    // Check for special character
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '`' && password[i] <= '~')
        {
            password_strength++;
        }
    }

    // Print password strength
    if (password_strength >= 3)
    {
        printf("Password strength: Strong\n");
    }
    else if (password_strength >= 2)
    {
        printf("Password strength: Moderate\n");
    }
    else if (password_strength >= 1)
    {
        printf("Password strength: Weak\n");
    }
    else
    {
        printf("Password strength: Very Weak\n");
    }

    return 0;
}