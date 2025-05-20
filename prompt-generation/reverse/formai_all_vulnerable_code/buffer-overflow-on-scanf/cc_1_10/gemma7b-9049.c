//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Password must be at least 8 characters long.\n");
    }
    else if (password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Password exceeds the maximum length of %d characters.\n", MAX_PASSWORD_LENGTH);
    }
    else if (!strcmp(password, "qwerty"))
    {
        printf("Sorry, that password is too common. Please choose another.\n");
    }
    else if (!isupper(password[0]))
    {
        printf("Password must start with an uppercase letter.\n");
    }
    else if (hasNumbers(password))
    {
        printf("Password must not contain any numbers.\n");
    }
    else
    {
        printf("Your password is strong.\n");
    }

    return 0;
}

int hasNumbers(char *password)
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