//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[255];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = strength - 1;
        printf("Error: Password too short.\n");
    }

    // Check for uppercase letter
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL)
    {
        strength = strength + 1;
    }

    // Check for lowercase letter
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL)
    {
        strength = strength + 1;
    }

    // Check for number
    if (strpbrk(password, "0123456789") != NULL)
    {
        strength = strength + 1;
    }

    // Check for special character
    if (strpbrk(password, "!@#$%^&*())_+-={}[]|\\:<>,.") != NULL)
    {
        strength = strength + 1;
    }

    // Calculate strength percentage
    int percentage = (strength / 4) * 100;

    // Print strength
    printf("Password strength: %d%%", percentage);

    return 0;
}