//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>

int password_strength(char *password)
{
    int strength = 0;
    int i = 0;

    while (password[i] != '\0')
    {
        // Check for uppercase letter
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }

        // Check for lowercase letter
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }

        // Check for number
        else if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }

        // Check for special character
        else if (password[i] >= '`' && password[i] <= '~')
        {
            strength++;
        }

        i++;
    }

    return strength;
}

int main()
{
    char password[20];
    int strength;

    printf("Enter a password: ");
    scanf("%s", password);

    strength = password_strength(password);

    switch (strength)
    {
        case 0:
            printf("Password is very weak!\n");
            break;
        case 1:
            printf("Password is weak!\n");
            break;
        case 2:
            printf("Password is moderate!\n");
            break;
        case 3:
            printf("Password is strong!\n");
            break;
        case 4:
            printf("Password is very strong!\n");
            break;
    }

    return 0;
}