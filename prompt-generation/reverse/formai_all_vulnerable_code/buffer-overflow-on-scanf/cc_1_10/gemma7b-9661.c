//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

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
        printf("Error: Your password is too short.\n");
    }
    else if (!islower(password[0]) && !isupper(password[0]))
    {
        printf("Error: Your password must start with a letter.\n");
    }
    else if (!isdigit(password[password_length - 1]))
    {
        printf("Error: Your password must end with a number.\n");
    }
    else if (hasRepeatCharacter(password))
    {
        printf("Error: Your password has a repeated character.\n");
    }
    else
    {
        printf("Your password is strong.\n");
    }

    return 0;
}

int hasRepeatCharacter(char *password)
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