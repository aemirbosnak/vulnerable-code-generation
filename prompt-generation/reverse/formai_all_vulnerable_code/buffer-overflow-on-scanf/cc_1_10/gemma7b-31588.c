//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[256];
    int strength = 0;

    printf("Welcome to the Galactic Password Checker!\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = strength - 10;
        printf("Error: Password must be at least 8 characters long.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength = strength - 5;
        printf("Error: Password must contain an uppercase letter.\n");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength = strength - 5;
        printf("Error: Password must contain a lowercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength = strength - 5;
        printf("Error: Password must contain a number.\n");
    }

    // Check for special character
    if (!strchr(password, '!'))
    {
        strength = strength - 5;
        printf("Error: Password must contain a special character.\n");
    }

    // Calculate strength
    strength = strength * 2;

    // Print strength
    printf("Your password strength is: %d/%d\n", strength, 100);

    return 0;
}