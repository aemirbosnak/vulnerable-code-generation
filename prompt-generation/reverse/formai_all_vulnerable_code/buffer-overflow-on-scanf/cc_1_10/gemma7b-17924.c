//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
    }
    else if (hasLowercase(password) && hasUppercase(password) && hasNumber(password) && hasSymbol(password))
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Error: Password is not strong enough.\n");
    }

    return 0;
}

int hasLowercase(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasUppercase(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasNumber(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasSymbol(char *password)
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (ispunct(password[i]))
        {
            return 1;
        }
    }

    return 0;
}