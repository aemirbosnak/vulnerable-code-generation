//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_LENGTH 8

int main()
{
    char password[MIN_LENGTH];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < MIN_LENGTH)
    {
        strength = 1;
    }

    // Check for uppercase letter
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL)
    {
        strength = 2;
    }

    // Check for lowercase letter
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL)
    {
        strength = 3;
    }

    // Check for number
    if (strpbrk(password, "0123456789") != NULL)
    {
        strength = 4;
    }

    // Check for special character
    if (strpbrk(password, "!@#$%^&*()_+-={}[]|\\:") != NULL)
    {
        strength = 5;
    }

    // Print password strength
    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        case 4:
            printf("Password strength: Very Strong\n");
            break;
        case 5:
            printf("Password strength: Excellent\n");
            break;
    }

    return 0;
}