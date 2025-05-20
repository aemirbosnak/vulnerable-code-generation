//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

void validate_password(char *password)
{
    int password_length = strlen(password);
    if (password_length < 8)
    {
        printf("Password must be at least 8 characters long.\n");
        return;
    }

    if (!isalnum(password[0]) && password[0] != '_')
    {
        printf("Password must start with an alphanumeric character or underscore.\n");
        return;
    }

    int has_number = 0;
    for (int i = 0; i < password_length; i++)
    {
        if (isdigit(password[i]))
        {
            has_number = 1;
        }
    }

    if (!has_number)
    {
        printf("Password must contain a number.\n");
        return;
    }

    int has_special_character = 0;
    for (int i = 0; i < password_length; i++)
    {
        if (ispunct(password[i]))
        {
            has_special_character = 1;
        }
    }

    if (!has_special_character)
    {
        printf("Password must contain a special character.\n");
        return;
    }

    printf("Password is valid.\n");
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    validate_password(password);

    return 0;
}