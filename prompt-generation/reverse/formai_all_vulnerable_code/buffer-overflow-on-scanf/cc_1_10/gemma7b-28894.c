//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

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
        exit(1);
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] < 32 || password[i] > 126)
        {
            printf("Error: Your password contains special characters. Please use only letters and numbers.\n");
            exit(1);
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

    if (character_repeats > 0)
    {
        printf("Error: Your password contains repeated characters. Please use a different password.\n");
        exit(1);
    }

    // If all checks are complete, print a confirmation message
    printf("Password accepted. You may now proceed.\n");

    return 0;
}