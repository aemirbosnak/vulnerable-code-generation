//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[256];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength -= 10;
    }

    // Check for uppercase letters
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL)
    {
        strength += 10;
    }

    // Check for lowercase letters
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL)
    {
        strength += 10;
    }

    // Check for numbers
    if (strpbrk(password, "0123456789") != NULL)
    {
        strength += 10;
    }

    // Check for symbols
    if (strpbrk(password, "!@#$%^&*()" ) != NULL)
    {
        strength += 10;
    }

    // Calculate strength
    strength = (strength / 10) * 10;

    // Print strength
    printf("Password strength: %d out of 10", strength);

    return 0;
}