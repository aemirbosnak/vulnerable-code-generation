//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) >= 8)
    {
        strength++;
    }

    // Check for uppercase letter
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
    }

    // Check for number
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
    }

    // Check for special character
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            strength++;
        }
    }

    // Display strength
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
            printf("Password strength: Excellent\n");
            break;
    }

    return 0;
}