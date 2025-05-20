//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LEN 255

int main()
{
    char password[MAX_PASS_LEN];
    int i, strength = 0, min_length = 0, has_number = 0, has_symbol = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < 8)
    {
        strength = -1;
        printf("Error: Password too short. Minimum 8 characters required.\n");
    }
    else
    {
        min_length = 1;
    }

    // Check for numbers
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            has_number = 1;
        }
    }

    // Check for symbols
    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbol = 1;
        }
    }

    // Calculate strength
    if (has_number && has_symbol)
    {
        strength = 3;
    }
    else if (has_number || has_symbol)
    {
        strength = 2;
    }
    else
    {
        strength = 1;
    }

    // Display strength
    switch (strength)
    {
        case 3:
            printf("Strength: Very strong.\n");
            break;
        case 2:
            printf("Strength: Strong.\n");
            break;
        case 1:
            printf("Strength: Weak.\n");
            break;
        case -1:
            printf("Strength: Invalid password.\n");
            break;
    }

    return 0;
}