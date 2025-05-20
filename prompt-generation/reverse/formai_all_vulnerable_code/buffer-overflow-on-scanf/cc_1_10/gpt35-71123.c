//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if the password contains at least one uppercase letter, one lowercase letter, one digit, and one special character.
int checkPasswordStrength(char password[])
{
    int len = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            hasUpper = 1;
        }
        else if (islower(password[i]))
        {
            hasLower = 1;
        }
        else if (isdigit(password[i]))
        {
            hasDigit = 1;
        }
        else
        {
            hasSpecial = 1;
        }
    }

    if (hasUpper && hasLower && hasDigit && hasSpecial)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Main Function
int main()
{
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    switch (strength)
    {
    case 0:
        printf("Your password is weak. Please include an uppercase letter, a lowercase letter, a digit, and a special character.\n");
        break;

    case 1:
        printf("Congratulations! Your password is strong!\n");
        break;

    default:
        printf("Invalid Input.\n");
    }

    return 0;
}