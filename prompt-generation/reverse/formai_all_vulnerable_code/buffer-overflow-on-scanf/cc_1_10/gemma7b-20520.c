//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

void password_strength(char *password)
{
    int password_length = strlen(password);
    int has_numbers = 0;
    int has_letters = 0;
    int has_symbols = 0;
    int is_too_short = 0;
    int is_too_long = 0;

    if (password_length < 8)
    {
        is_too_short = 1;
    }
    else if (password_length > MAX_PASSWORD_LENGTH)
    {
        is_too_long = 1;
    }

    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            has_numbers = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_letters = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbols = 1;
        }
    }

    if (has_numbers && has_letters && has_symbols)
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is weak.\n");
    }

    if (is_too_short)
    {
        printf("Password is too short. Please use at least 8 characters.\n");
    }
    if (is_too_long)
    {
        printf("Password is too long. Please use a maximum of %d characters.\n", MAX_PASSWORD_LENGTH);
    }
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    password_strength(password);

    return 0;
}