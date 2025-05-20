//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Password is too short. Minimum 8 characters required.\n");
    }
    else if (password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Password is too long. Maximum %d characters allowed.\n", MAX_PASSWORD_LENGTH);
    }
    else if (!is_strong_password(password))
    {
        printf("Password is not strong. Please use a stronger password.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}

int is_strong_password(char *password)
{
    int i = 0;
    char upper_case_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_case_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";

    for (i = 0; password[i] != '\0'; i++)
    {
        // Check for upper case letter
        if (strchr(upper_case_letters, password[i]) != NULL)
        {
            return 1;
        }

        // Check for lower case letter
        if (strchr(lower_case_letters, password[i]) != NULL)
        {
            return 1;
        }

        // Check for number
        if (strchr(numbers, password[i]) != NULL)
        {
            return 1;
        }
    }

    return 0;
}