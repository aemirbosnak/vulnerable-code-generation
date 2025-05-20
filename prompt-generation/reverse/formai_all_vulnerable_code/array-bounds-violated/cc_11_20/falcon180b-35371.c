//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int length, i;

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove newline character
    password[length - 1] = '\0';

    // Check for empty password
    if (length == 0)
    {
        printf("Password is empty.\n");
        return 1;
    }

    // Check for whitespace characters
    for (i = 0; i < length; i++)
    {
        if (isspace(password[i]))
        {
            printf("Password contains whitespace characters.\n");
            return 1;
        }
    }

    // Check for special characters
    int has_special_char = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;

    for (i = 0; i < length; i++)
    {
        if (isalnum(password[i]))
        {
            has_special_char = 1;
        }
        else if (isupper(password[i]))
        {
            has_uppercase = 1;
        }
        else if (islower(password[i]))
        {
            has_lowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            has_number = 1;
        }
    }

    if (!has_special_char)
    {
        printf("Password does not contain special characters.\n");
        return 1;
    }

    if (!has_uppercase)
    {
        printf("Password does not contain uppercase letters.\n");
        return 1;
    }

    if (!has_lowercase)
    {
        printf("Password does not contain lowercase letters.\n");
        return 1;
    }

    if (!has_number)
    {
        printf("Password does not contain numbers.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}