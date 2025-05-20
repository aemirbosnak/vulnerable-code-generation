//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
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
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Calculate the password length
    password_length = strlen(password);

    // Check if the password meets the minimum length requirement
    if (password_length < 8)
    {
        printf("Error: Your password is too short.\n");
        return 1;
    }

    // Check if the password contains any special characters
    if (!strpbrk(password, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123"))
    {
        printf("Error: Your password does not contain any special characters.\n");
        return 1;
    }

    // Check if the password contains any repeated characters
    if (has_repeated_characters(password))
    {
        printf("Error: Your password contains repeated characters.\n");
        return 1;
    }

    // The password meets all requirements
    printf("Your password is strong.\n");

    return 0;
}

int has_repeated_characters(char *password)
{
    int i = 0;
    int character_count[256] = {0};

    // Iterate over the password and count the occurrences of each character
    for (i = 0; password[i] != '\0'; i++)
    {
        character_count[password[i]]++;
    }

    // Check if any character occurs more than once
    for (i = 0; character_count[i] > 1; i++)
    {
        return 1;
    }

    return 0;
}