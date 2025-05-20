//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        strength -= 1;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength -= 1;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength -= 1;
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength -= 1;
    }

    // Check for special character
    if (!strchr(password, '!'))
    {
        strength -= 1;
    }

    // Calculate strength percentage
    strength = (strength / 5) * 100;

    // Print strength
    printf("Your password strength is: %d%%", strength);

    return 0;
}