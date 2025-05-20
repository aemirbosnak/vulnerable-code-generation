//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check for uppercase letters
    for (int i = 0; i < 20; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < 20; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
    }

    // Check for numbers
    for (int i = 0; i < 20; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
    }

    // Check for special characters
    for (int i = 0; i < 20; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            strength++;
        }
    }

    // Calculate password strength
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