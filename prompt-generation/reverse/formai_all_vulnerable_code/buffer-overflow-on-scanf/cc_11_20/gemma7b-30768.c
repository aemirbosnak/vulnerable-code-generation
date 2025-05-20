//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[20];
    int i, strength = 0, min_length = 8;
    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < min_length)
    {
        printf("Password must be at least %d characters long.\n", min_length);
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;
    }

    // Check for lowercase letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;
    }

    // Check for number
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
            strength++;
    }

    // Check for special character
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '!' && password[i] <= '@')
            strength++;
    }

    // Calculate strength percentage
    strength = (strength / strlen(password)) * 100;

    // Print strength
    printf("Password strength: %d%%", strength);

    return 0;
}