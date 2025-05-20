//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        strength--;
        printf("Password too short.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength--;
        printf("Password lacks uppercase letter.\n");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength--;
        printf("Password lacks lowercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength--;
        printf("Password lacks number.\n");
    }

    // Check for special character
    if (!strchr(password, '!'))
    {
        strength--;
        printf("Password lacks special character.\n");
    }

    // Calculate strength
    strength = strength * password_length;

    // Print strength
    printf("Password strength: %d/%d\n", strength, MAX_PASSWORD_LENGTH);

    return 0;
}