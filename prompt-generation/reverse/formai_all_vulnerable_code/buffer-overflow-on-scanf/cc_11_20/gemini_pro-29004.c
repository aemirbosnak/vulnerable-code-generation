//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Length of the password
#define LEN 100

// Function to check the strength of the password
int check_strength(char *password)
{
    int strength = 0;

    // Check the length of the password
    if (strlen(password) < 8)
    {
        strength++;
    }

    // Check for the presence of uppercase characters
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase)
    {
        strength++;
    }

    // Check for the presence of lowercase characters
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase)
    {
        strength++;
    }

    // Check for the presence of digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit)
    {
        strength++;
    }

    // Check for the presence of special characters
    int has_special = 0;
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%')
        {
            has_special = 1;
            break;
        }
    }
    if (!has_special)
    {
        strength++;
    }

    // Return the strength of the password
    return strength;
}

int main()
{
    // Get the password from the user
    char password[LEN];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_strength(password);

    // Print the strength of the password
    if (strength == 0)
    {
        printf("Your password is very strong.\n");
    }
    else if (strength == 1)
    {
        printf("Your password is strong.\n");
    }
    else if (strength == 2)
    {
        printf("Your password is moderate.\n");
    }
    else
    {
        printf("Your password is weak.\n");
    }

    return 0;
}