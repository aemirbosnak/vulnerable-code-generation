//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[255];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < 8)
    {
        strength++;
    }

    // Check for numbers
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
    }

    // Check for special characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '!' && password[i] <= '@')
        {
            strength++;
        }
    }

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
    }

    return 0;
}