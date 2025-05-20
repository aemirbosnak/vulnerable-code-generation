//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

void check_password_strength(char *password)
{
    int password_length = strlen(password);
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_number = 0;
    int has_special_character = 0;

    for (int i = 0; i < password_length; i++)
    {
        char character = password[i];

        if (character >= 'a' && character <= 'z')
        {
            has_lower_case = 1;
        }
        else if (character >= 'A' && character <= 'Z')
        {
            has_upper_case = 1;
        }
        else if (character >= '0' && character <= '9')
        {
            has_number = 1;
        }
        else if (character >= '`' && character <= '~')
        {
            has_special_character = 1;
        }
    }

    if (password_length < 8)
    {
        printf("Password is too short.\n");
    }
    else if (!has_upper_case)
    {
        printf("Password lacks upper case letter.\n");
    }
    else if (!has_lower_case)
    {
        printf("Password lacks lower case letter.\n");
    }
    else if (!has_number)
    {
        printf("Password lacks number.\n");
    }
    else if (!has_special_character)
    {
        printf("Password lacks special character.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}