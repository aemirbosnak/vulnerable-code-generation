//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int i;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    for (i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            printf("Error: Password contains non-alphanumeric characters.\n");
            return 1;
        }
    }

    if (password_length < 8)
    {
        printf("Error: Password is too short.\n");
        return 1;
    }

    if (hasUppercase(password))
    {
        printf("Password has uppercase letters.\n");
    }

    if (hasLowercase(password))
    {
        printf("Password has lowercase letters.\n");
    }

    if (hasNumbers(password))
    {
        printf("Password has numbers.\n");
    }

    if (hasSymbol(password))
    {
        printf("Password has symbols.\n");
    }

    printf("Password is strong.\n");

    return 0;
}

int hasUppercase(char *password)
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasLowercase(char *password)
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasNumbers(char *password)
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
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
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (!isalnum(password[i]))
        {
            return 1;
        }
    }

    return 0;
}