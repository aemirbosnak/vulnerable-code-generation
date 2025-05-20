//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;
    char letter_found = 0;
    char number_found = 0;
    char symbol_found = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Calculate password strength
    for (int i = 0; i < password_length; i++)
    {
        char character = password[i];

        // Check for letters
        if (character >= 'a' && character <= 'z')
        {
            letter_found = 1;
        }

        // Check for numbers
        if (character >= '0' && character <= '9')
        {
            number_found = 1;
        }

        // Check for symbols
        if (character >= '!' && character <= '~')
        {
            symbol_found = 1;
        }

        // Add points for each character type
        if (letter_found)
        {
            strength++;
        }

        if (number_found)
        {
            strength++;
        }

        if (symbol_found)
        {
            strength++;
        }
    }

    // Print password strength
    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 2:
            printf("Your password is moderately strong. It may be adequate for some purposes.\n");
            break;
        case 3:
            printf("Your password is strong. It is difficult to guess.\n");
            break;
        case 4:
            printf("Your password is very strong. It is extremely difficult to guess.\n");
            break;
    }

    return 0;
}