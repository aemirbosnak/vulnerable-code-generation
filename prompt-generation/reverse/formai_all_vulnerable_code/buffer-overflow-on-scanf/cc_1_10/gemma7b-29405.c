//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define PASSWORD_LENGTH 20

int main()
{
    char password[PASSWORD_LENGTH];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < PASSWORD_LENGTH)
    {
        printf("Error: Password must be at least %d characters long.\n", PASSWORD_LENGTH);
        return 1;
    }

    // Check for uppercase letter
    if (isupper(password[0]) || isupper(password[1]))
    {
        strength++;
    }

    // Check for lowercase letter
    if (islower(password[0]) || islower(password[1]))
    {
        strength++;
    }

    // Check for number
    if (isdigit(password[0]) || isdigit(password[1]))
    {
        strength++;
    }

    // Check for special character
    if (ispunct(password[0]) || ispunct(password[1]))
    {
        strength++;
    }

    // Calculate strength percentage
    int percentage = (strength / PASSWORD_LENGTH) * 100;

    // Print strength
    printf("Password strength: %d%% (%d/20 characters strong)\n", percentage, strength);

    return 0;
}