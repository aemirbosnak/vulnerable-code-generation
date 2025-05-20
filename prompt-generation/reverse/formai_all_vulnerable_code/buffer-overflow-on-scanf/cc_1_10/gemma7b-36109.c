//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check if the password meets the minimum length requirements
    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
        return 1;
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            printf("Error: Password may not contain special characters.\n");
            return 1;
        }
    }

    // Check if the password contains any repeated characters
    int character_map[256] = {0};
    for (int i = 0; i < password_length; i++)
    {
        character_map[password[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (character_map[i] > 1)
        {
            printf("Error: Password may not contain repeated characters.\n");
            return 1;
        }
    }

    // The password meets all requirements
    printf("Your password is valid.\n");

    return 0;
}