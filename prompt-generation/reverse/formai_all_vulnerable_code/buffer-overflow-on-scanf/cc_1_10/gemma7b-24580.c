//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void password_strength(char *password)
{
    int strength = 0;
    int min_length = 8;

    // Check for minimum length
    if (strlen(password) < min_length)
    {
        strength -= 10;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength -= 5;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength -= 5;
    }

    // Check for number
    if (!strchr(password, '0'))
    {
        strength -= 5;
    }

    // Check for special character
    if (!strchr(password, '!'))
    {
        strength -= 5;
    }

    // Calculate strength percentage
    int percentage = strength * 100 / min_length;

    // Print strength
    printf("Your password strength is: %d%%", percentage);
}

int main()
{
    char password[256];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    password_strength(password);

    return 0;
}