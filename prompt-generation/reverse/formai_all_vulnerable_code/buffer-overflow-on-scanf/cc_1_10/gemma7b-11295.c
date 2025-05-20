//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int passwordStrength(char *password)
{
    int strength = 0;
    int i = 0;
    char character;

    // Iterate over the password character by character
    while (password[i] != '\0')
    {
        character = password[i];

        // Check for uppercase letter
        if (character >= 'A' && character <= 'Z')
        {
            strength++;
        }

        // Check for lowercase letter
        if (character >= 'a' && character <= 'z')
        {
            strength++;
        }

        // Check for number
        if (character >= '0' && character <= '9')
        {
            strength++;
        }

        // Check for special character
        if (character >= '! ' && character <= '~')
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

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = passwordStrength(password);

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