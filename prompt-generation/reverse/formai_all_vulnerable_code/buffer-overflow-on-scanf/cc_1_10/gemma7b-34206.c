//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the length of the password
    password_length = strlen(password);

    // Check if the password meets the minimum length requirements
    if (password_length < 8)
    {
        printf("Error: Your password is too short. Please use at least 8 characters.\n");
        return 1;
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] < 32 || password[i] > 126)
        {
            printf("Error: Your password contains special characters. Please use only alphanumeric characters.\n");
            return 1;
        }
    }

    // Check if the password contains any repeated characters
    int character_repeats = 0;
    for (int i = 0; i < password_length - 1; i++)
    {
        for (int j = i + 1; j < password_length; j++)
        {
            if (password[i] == password[j])
            {
                character_repeats++;
            }
        }
    }

    // If there are no character repeats, print a message
    if (character_repeats == 0)
    {
        printf("Your password is strong.\n");
    }
    else
    {
        printf("Error: Your password contains repeated characters. Please use a different password.\n");
    }

    return 0;
}