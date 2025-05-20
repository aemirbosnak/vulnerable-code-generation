//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_MIN_LENGTH 8

int main()
{
    char password[PASSWORD_MIN_LENGTH];

    printf("Welcome to the Mighty Password Fortress!\n");
    printf("Please enter your password: ");

    scanf("%s", password);

    if (strlen(password) < PASSWORD_MIN_LENGTH)
    {
        printf("Error: Your password is too short.\n");
    }
    else if (!strcmp(password, "TheSecret"))
    {
        printf("Error: Your password is not strong enough. It is the secret password.\n");
    }
    else if (hasUppercase(password) && hasLowercase(password) && hasNumber(password))
    {
        printf("Congratulations! Your password is strong.\n");
    }
    else
    {
        printf("Error: Your password is not strong enough. It lacks one of the following: uppercase letter, lowercase letter, or number.\n");
    }

    return 0;
}

int hasUppercase(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
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
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasNumber(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isdigit(password[i]))
        {
            return 1;
        }
    }

    return 0;
}