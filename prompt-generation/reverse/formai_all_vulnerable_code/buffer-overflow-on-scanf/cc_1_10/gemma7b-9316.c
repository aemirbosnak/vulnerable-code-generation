//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main()
{
    char password[256];
    int password_length = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
    }
    else if (password_length > 24)
    {
        printf("Error: Password must be 24 characters or less.\n");
    }
    else if (!islower(password[0]) && !isupper(password[0]))
    {
        printf("Error: Password must start with a letter.\n");
    }
    else if (has_duplicate_characters(password))
    {
        printf("Error: Password cannot have duplicate characters.\n");
    }
    else
    {
        printf("Password is valid.\n");
    }

    return 0;
}

int has_duplicate_characters(char *password)
{
    int character_map[256] = {0};
    int i = 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (character_map[password[i]]++ > 1)
        {
            return 1;
        }
    }

    return 0;
}