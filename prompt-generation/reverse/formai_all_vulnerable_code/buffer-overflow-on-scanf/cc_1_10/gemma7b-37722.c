//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

void check_password_strength(char *password)
{
    int password_length = strlen(password);
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_numbers = 0;
    int has_symbols = 0;

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
            has_numbers = 1;
        }
        else if (character >= '!' && character <= '~')
        {
            has_symbols = 1;
        }
    }

    if (has_upper_case && has_lower_case && has_numbers && has_symbols)
    {
        printf("Your password is strong.\n");
    }
    else
    {
        printf("Your password is weak. Please use a stronger password.\n");
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