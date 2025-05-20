//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MIN_LENGTH 8

int main()
{
    char password[PASSWORD_MIN_LENGTH];
    int password_length;
    int i;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < PASSWORD_MIN_LENGTH)
    {
        printf("Error: Password must be at least %d characters long.\n", PASSWORD_MIN_LENGTH);
        return 1;
    }

    // Check for upper case letters
    for (i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
            strength++;
    }

    // Check for lowercase letters
    for (i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
            strength++;
    }

    // Check for numbers
    for (i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
            strength++;
    }

    // Check for special characters
    for (i = 0; i < password_length; i++)
    {
        if (ispunct(password[i]))
            strength++;
    }

    // Calculate password strength
    strength = strength * 100 / password_length;

    // Print password strength
    printf("Password strength: %d%%\n", strength);

    return 0;
}