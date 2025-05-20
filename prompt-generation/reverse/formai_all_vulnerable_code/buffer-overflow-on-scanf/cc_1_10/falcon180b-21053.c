//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_special_char(char c)
{
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*');
}

int is_valid_password(char *password)
{
    int length = strlen(password);
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (is_lowercase(password[i]))
        {
            has_lowercase = 1;
        }
        else if (is_uppercase(password[i]))
        {
            has_uppercase = 1;
        }
        else if (is_digit(password[i]))
        {
            has_digit = 1;
        }
        else if (is_special_char(password[i]))
        {
            has_special_char = 1;
        }
    }

    if (has_lowercase && has_uppercase && has_digit && has_special_char)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    if (is_valid_password(password))
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is weak.\n");
    }

    return 0;
}