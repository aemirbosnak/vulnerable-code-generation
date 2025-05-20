//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        printf("Error: Password must be at least 8 characters long.\n");
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            printf("Error: Password may not contain special characters.\n");
            break;
        }
    }

    // Check if the password contains any repeated characters
    for (int i = 0; i < password_length - 1; i++)
    {
        for (int j = i + 1; j < password_length; j++)
        {
            if (password[i] == password[j])
            {
                printf("Error: Password may not contain repeated characters.\n");
                break;
            }
        }
    }

    // If the password meets all requirements, print a confirmation message
    if (password_length >= 8 && !isalnum(password[0]) && !contains_repeated_characters(password))
    {
        printf("Password accepted.\n");
    }

    return 0;
}

int contains_repeated_characters(char *password)
{
    for (int i = 0; i < strlen(password) - 1; i++)
    {
        for (int j = i + 1; j < strlen(password); j++)
        {
            if (password[i] == password[j])
            {
                return 1;
            }
        }
    }

    return 0;
}