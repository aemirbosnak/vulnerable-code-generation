//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[255];
    int strength = 0;
    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = strength - 10;
        printf("Password too short, at least 8 characters needed.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength = strength - 5;
        printf("Password lacks uppercase letter.\n");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength = strength - 5;
        printf("Password lacks lowercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength = strength - 5;
        printf("Password lacks number.\n");
    }

    // Check for symbol
    if (!strchr(password, '$') && !strchr(password, '%') && !strchr(password, '&'))
    {
        strength = strength - 5;
        printf("Password lacks symbol.\n");
    }

    // Calculate strength
    strength = strength / 5;

    // Print strength
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
        default:
            printf("Error.\n");
            break;
    }

    return 0;
}