//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LEN 255

int main()
{
    char password[MAX_PASSWORD_LEN];
    int password_length = 0;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for minimum length
    if (password_length < 8)
    {
        strength = -1;
        printf("Error: Password must be at least 8 characters long.\n");
    }

    // Check for uppercase letter
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL)
    {
        strength++;
    }

    // Check for lowercase letter
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL)
    {
        strength++;
    }

    // Check for number
    if (strpbrk(password, "0123456789") != NULL)
    {
        strength++;
    }

    // Check for symbol
    if (strpbrk(password, "!@#$%^&*())_+-={}[]|\\:<>,.?|") != NULL)
    {
        strength++;
    }

    // Calculate strength percentage
    strength = (strength / 5) * 100;

    // Print strength
    printf("Password Strength: %d%%", strength);

    return 0;
}