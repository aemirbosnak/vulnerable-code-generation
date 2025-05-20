//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int i, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for minimum length
    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
            strength++;
    }

    // Check for lowercase letter
    for (i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
            strength++;
    }

    // Check for number
    for (i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
            strength++;
    }

    // Check for special character
    for (i = 0; i < password_length; i++)
    {
        if (ispunct(password[i]))
            strength++;
    }

    // Calculate strength percentage
    strength = (strength / password_length) * 100;

    // Print strength
    printf("Password strength: %d%%", strength);

    return 0;
}