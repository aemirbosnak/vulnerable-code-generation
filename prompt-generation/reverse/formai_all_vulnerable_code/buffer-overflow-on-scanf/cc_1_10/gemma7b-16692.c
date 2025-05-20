//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < min_length)
    {
        printf("Error: Password must be at least %d characters long.\n", min_length);
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            strength++;
    }

    // Check for lowercase letter
    for (i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
            strength++;
    }

    // Check for number
    for (i = 0; password[i] != '\0'; i++)
    {
        if (isdigit(password[i]))
            strength++;
    }

    // Check for special character
    for (i = 0; password[i] != '\0'; i++)
    {
        if (!isalnum(password[i]))
            strength++;
    }

    // Calculate strength percentage
    strength = (strength / 4) * 100;

    // Print strength
    printf("Password strength: %d%%", strength);

    return 0;
}