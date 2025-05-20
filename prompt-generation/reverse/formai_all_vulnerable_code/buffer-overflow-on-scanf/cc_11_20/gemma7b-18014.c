//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 16

int main()
{
    char password[PASSWORD_LENGTH] = "";
    int i = 0;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < PASSWORD_LENGTH)
    {
        printf("Error: password too short.\n");
        exit(1);
    }

    // Check for uppercase letter
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
    }

    // Check for number
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
    }

    // Check for special character
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= '!' && password[i] <= '@')
        {
            strength++;
        }
    }

    // Calculate password strength
    switch (strength)
    {
        case 0:
            printf("Password strength: Weak.\n");
            break;
        case 1:
            printf("Password strength: Moderate.\n");
            break;
        case 2:
            printf("Password strength: Strong.\n");
            break;
        case 3:
            printf("Password strength: Very Strong.\n");
            break;
        default:
            printf("Error: invalid password.\n");
            exit(1);
    }

    return 0;
}