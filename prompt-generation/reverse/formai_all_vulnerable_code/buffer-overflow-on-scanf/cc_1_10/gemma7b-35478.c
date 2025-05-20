//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
    }
    else if (!islower(password[0]) && !isupper(password[0]))
    {
        printf("Error: Password must start with a letter.\n");
    }
    else if (!isalnum(password[password_length - 1]))
    {
        printf("Error: Password must end with a number or letter.\n");
    }
    else if (hasRepeatCharacter(password))
    {
        printf("Error: Password has repeated characters.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}

int hasRepeatCharacter(char *password)
{
    int i, character_count[256] = {0};

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