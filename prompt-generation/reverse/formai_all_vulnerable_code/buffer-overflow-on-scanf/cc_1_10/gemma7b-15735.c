//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define PASSWORD_MAX_LENGTH 256

int main()
{
    char password[PASSWORD_MAX_LENGTH];
    int password_length;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Error: Password must be at least 8 characters long.\n");
    }
    else if (password_length > PASSWORD_MAX_LENGTH)
    {
        printf("Error: Password is too long.\n");
    }
    else if (!islower(password[0]) && !isupper(password[0]))
    {
        printf("Error: Password must start with a letter.\n");
    }
    else if (!isalnum(password[password_length - 1]))
    {
        printf("Error: Password must end with a number or letter.\n");
    }
    else if (check_password_complexity(password))
    {
        printf("Error: Password is not complex enough.\n");
    }
    else
    {
        printf("Password is valid.\n");
    }

    return 0;
}

int check_password_complexity(char *password)
{
    int i;
    int password_length = strlen(password);

    for (i = 0; i < password_length; i++)
    {
        if (!isupper(password[i]) && !islower(password[i]) && !isdigit(password[i]))
        {
            return 1;
        }
    }

    return 0;
}