//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

void validate_password(char *password)
{
    int password_length = strlen(password);

    // Check if the password is too short
    if (password_length < 8)
    {
        printf("Error: Password is too short.\n");
        exit(1);
    }

    // Check if the password contains any special characters
    for (int i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            printf("Error: Password contains special characters.\n");
            exit(1);
        }
    }

    // Check if the password has enough numbers
    int num_count = 0;
    for (int i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
        {
            num_count++;
        }
    }
    if (num_count < 2)
    {
        printf("Error: Password lacks enough numbers.\n");
        exit(1);
    }

    // Check if the password has enough uppercase letters
    int upper_count = 0;
    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            upper_count++;
        }
    }
    if (upper_count < 2)
    {
        printf("Error: Password lacks enough uppercase letters.\n");
        exit(1);
    }

    // Password is valid
    printf("Password is valid.\n");
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    validate_password(password);

    return 0;
}