//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Password too short.\n");
    }
    else if (password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Password too long.\n");
    }
    else if (!is_strong_password(password))
    {
        printf("Password not strong enough.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}

int is_strong_password(char *password)
{
    int i;
    int password_strength = 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            password_strength++;
        }
        else if (islower(password[i]))
        {
            password_strength++;
        }
        else if (isdigit(password[i]))
        {
            password_strength++;
        }
        else if (ispunct(password[i]))
        {
            password_strength++;
        }
    }

    if (password_strength >= 3)
    {
        return 1;
    }

    return 0;
}