//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculate the password length
    password_length = strlen(password);

    // Check if the password meets the minimum length requirement
    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
    }

    // Check if the password contains any special characters
    if (!strpbrk(password, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123"))
    {
        printf("Error: Password must contain at least one special character.\n");
    }

    // Check if the password contains any numbers
    if (!strpbrk(password, "0123"))
    {
        printf("Error: Password must contain at least one number.\n");
    }

    // Check if the password contains any uppercase letters
    if (!strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
    {
        printf("Error: Password must contain at least one uppercase letter.\n");
    }

    // Check if the password contains any repeated characters
    if (has_repeated_characters(password))
    {
        printf("Error: Password cannot contain repeated characters.\n");
    }

    // If the password meets all requirements, print a confirmation message
    if (password_length >= 8 && strpbrk(password, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123") && strpbrk(password, "0123") && strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") && !has_repeated_characters(password))
    {
        printf("Password accepted.\n");
    }

    return 0;
}

int has_repeated_characters(char *password)
{
    int i = 0;
    int character_count[256] = {0};

    for (i = 0; password[i] != '\0'; i++)
    {
        character_count[password[i]]++;
    }

    for (i = 0; character_count[i] > 1; i++)
    {
        return 1;
    }

    return 0;
}