//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int strength = 0;
    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length of 8 characters
    if (strlen(password) < 8)
    {
        strength = strength - 1;
    }

    // Check for presence of numbers
    if (!isdigit(password[0]) && !isdigit(password[1]) && !isdigit(password[2]))
    {
        strength = strength - 1;
    }

    // Check for presence of uppercase letters
    if (!isupper(password[0]) && !isupper(password[1]) && !isupper(password[2]))
    {
        strength = strength - 1;
    }

    // Check for presence of special characters
    if (!ispunct(password[0]) && !ispunct(password[1]) && !ispunct(password[2]))
    {
        strength = strength - 1;
    }

    // Calculate password strength
    strength = strength + (strlen(password) - 8) * 2;

    // Print password strength
    switch (strength)
    {
        case 5:
            printf("Your password is very strong.\n");
            break;
        case 4:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is moderate.\n");
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