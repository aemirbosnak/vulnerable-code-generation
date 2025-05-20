//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
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
        printf("Password too short, minimum 8 characters required.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength -= 1;
        printf("Password needs an uppercase letter.\n");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength -= 1;
        printf("Password needs a lowercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength -= 1;
        printf("Password needs a number.\n");
    }

    // Check for special character
    if (!strchr(password, '$') && !strchr(password, '&') && !strchr(password, '*'))
    {
        strength -= 1;
        printf("Password needs a special character.\n");
    }

    // Calculate strength percentage
    strength = strength * 100 / 4;

    // Print strength
    printf("Password strength: %d%%", strength);

    return 0;
}