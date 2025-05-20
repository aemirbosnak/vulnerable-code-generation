//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 255

int main()
{
    char password[MAX_PASS_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Calculate password strength based on statistical factors
    for (int i = 0; i < password_length; i++)
    {
        int character_strength = 0;

        // Check for uppercase letter
        if (isupper(password[i]))
            character_strength++;

        // Check for lowercase letter
        if (islower(password[i]))
            character_strength++;

        // Check for number
        if (isdigit(password[i]))
            character_strength++;

        // Check for special character
        if (ispunct(password[i]))
            character_strength++;

        strength += character_strength;
    }

    // Display password strength
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