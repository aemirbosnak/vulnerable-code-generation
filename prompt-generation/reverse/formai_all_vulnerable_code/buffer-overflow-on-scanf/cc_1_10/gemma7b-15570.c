//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[256];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength -= 1;
        printf("Error: Password too short.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength -= 1;
        printf("Error: Password needs an uppercase letter.\n");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength -= 1;
        printf("Error: Password needs a lowercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength -= 1;
        printf("Error: Password needs a number.\n");
    }

    // Check for special character
    if (!strchr(password, '!'))
    {
        strength -= 1;
        printf("Error: Password needs a special character.\n");
    }

    // Calculate strength
    strength = 10 - strength;

    // Display strength
    printf("Password strength: %d/%d\n", strength, 10);

    return 0;
}