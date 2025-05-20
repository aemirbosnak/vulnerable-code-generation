//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_MINIMUM_LENGTH 8

int main()
{
    char password[PASSWORD_MINIMUM_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password meets the minimum length requirement
    if (strlen(password) < PASSWORD_MINIMUM_LENGTH)
    {
        printf("Error: Password must be at least %d characters long.\n", PASSWORD_MINIMUM_LENGTH);
    }
    // Check if the password contains any special characters
    else if (hasSpecialCharacters(password))
    {
        printf("Error: Password cannot contain special characters.\n");
    }
    // Check if the password contains any repeated characters
    else if (hasRepeatedCharacters(password))
    {
        printf("Error: Password cannot contain repeated characters.\n");
    }
    // Check if the password is strong
    else if (isStrongPassword(password))
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Error: Password is not strong.\n");
    }

    return 0;
}

int hasSpecialCharacters(char *password)
{
    return strpbrk(password, "!@#$%^&*())_+-={}[]|\\:.;") != NULL;
}

int hasRepeatedCharacters(char *password)
{
    int i, count = 0;
    for (i = 0; password[i] != '\0'; i++)
    {
        char character = password[i];
        for (int j = i + 1; password[j] != '\0'; j++)
        {
            if (character == password[j])
            {
                count++;
            }
        }
    }
    return count > 0;
}

int isStrongPassword(char *password)
{
    return (strlen(password) >= PASSWORD_MINIMUM_LENGTH) && !hasSpecialCharacters(password) && !hasRepeatedCharacters(password);
}