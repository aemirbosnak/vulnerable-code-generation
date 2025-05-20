//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MINIMUM_LENGTH 8

int main()
{
    char password[PASSWORD_MINIMUM_LENGTH];
    int password_length;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < PASSWORD_MINIMUM_LENGTH)
    {
        printf("Password too short, must be at least %d characters.\n", PASSWORD_MINIMUM_LENGTH);
    }
    else if (strcmp(password, "qwerty") == 0)
    {
        printf("Weak password, please use a different one.\n");
    }
    else if (hasUppercaseLetter(password) && hasNumber(password))
    {
        printf("Strong password.\n");
    }
    else
    {
        printf("Password is not strong, please use one that meets the following criteria:\n"
               " - At least %d characters\n"
               " - Contains an uppercase letter\n"
               " - Contains a number\n", PASSWORD_MINIMUM_LENGTH);
    }

    return 0;
}

int hasUppercaseLetter(char *password)
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