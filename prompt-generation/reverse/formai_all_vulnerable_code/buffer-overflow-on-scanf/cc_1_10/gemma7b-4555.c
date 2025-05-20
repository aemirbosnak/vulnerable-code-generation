//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check if the password meets the minimum length requirement
    if (password_length < 8)
    {
        printf("Error: Your password is too short. Minimum 8 characters required.\n");
        return 1;
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] < 32 || password[i] > 126)
        {
            printf("Error: Your password contains special characters. Please use only letters and numbers.\n");
            return 1;
        }
    }

    // Check if the password contains any repeated characters
    int character_count[MAX_PASSWORD_LENGTH] = {0};
    for (int i = 0; i < password_length; i++)
    {
        character_count[password[i]]++;
    }

    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++)
    {
        if (character_count[i] > 1)
        {
            printf("Error: Your password contains repeated characters. Please use a different password.\n");
            return 1;
        }
    }

    // If all checks are complete, the password is valid
    printf("Your password is valid.\n");

    return 0;
}