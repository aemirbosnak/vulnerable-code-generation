//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_MINIMUM_LENGTH 8

int main()
{
    char password[PASSWORD_MINIMUM_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password meets the minimum length requirements
    if (strlen(password) < PASSWORD_MINIMUM_LENGTH)
    {
        printf("Error: Password must be at least %d characters long.\n", PASSWORD_MINIMUM_LENGTH);
        return 1;
    }

    // Check if the password contains any special characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] < 32 || password[i] > 126)
        {
            printf("Error: Password cannot contain special characters.\n");
            return 1;
        }
    }

    // Check if the password contains any repeated characters
    int character_count[256] = {0};
    for (int i = 0; i < strlen(password); i++)
    {
        character_count[password[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (character_count[i] > 1)
        {
            printf("Error: Password cannot contain repeated characters.\n");
            return 1;
        }
    }

    // If all conditions are met, print a confirmation message
    printf("Password accepted.\n");

    return 0;
}