//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    int i, strength = 0, min_length = 8;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length)
    {
        printf("Error: Password too short. Minimum %d characters required.\n", min_length);
        return 1;
    }

    // Check for lowercase letter
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;
    }

    // Check for uppercase letter
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;
    }

    // Check for number
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
            strength++;
    }

    // Check for special character
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
            strength++;
    }

    // Calculate strength percentage
    strength = (strength / (min_length - 1)) * 100;

    // Print strength
    printf("Password Strength: %d%%", strength);

    return 0;
}