//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    int i, strength = 0, hasNumbers = 0, hasUppercase = 0, hasLowercase = 0, hasSymbols = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowercase = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasNumbers = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            hasSymbols = 1;
        }
    }

    if (hasNumbers && hasUppercase && hasLowercase && hasSymbols)
    {
        strength = 5;
    }
    else if (hasNumbers && hasUppercase && hasLowercase)
    {
        strength = 4;
    }
    else if (hasNumbers && hasUppercase)
    {
        strength = 3;
    }
    else if (hasNumbers)
    {
        strength = 2;
    }
    else
    {
        strength = 1;
    }

    switch (strength)
    {
        case 5:
            printf("Your password is extremely strong.\n");
            break;
        case 4:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is moderately strong.\n");
            break;
        case 2:
            printf("Your password is weak.\n");
            break;
        case 1:
            printf("Your password is very weak.\n");
            break;
    }

    return 0;
}