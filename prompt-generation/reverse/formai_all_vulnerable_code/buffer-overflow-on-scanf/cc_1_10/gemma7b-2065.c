//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, length = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for minimum length
    if (length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            strength++;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            strength++;
        }
    }

    // Check for number
    for (i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
        {
            strength++;
        }
    }

    // Check for special character
    for (i = 0; i < length; i++)
    {
        if (ispunct(password[i]))
        {
            strength++;
        }
    }

    // Calculate strength percentage
    strength = strength * 100 / length;

    // Print strength
    printf("Password Strength: %d%%", strength);

    return 0;
}