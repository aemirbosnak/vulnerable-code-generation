//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password length
    password_length = strlen(password);

    // Check if the password meets the minimum length requirement
    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
        return 1;
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] < 32 || password[i] > 126)
        {
            printf("Error: Password may not contain special characters.\n");
            return 1;
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
                return 1;
            }
        }
    }

    // Password meets all requirements
    printf("Your password is strong.\n");

    return 0;
}