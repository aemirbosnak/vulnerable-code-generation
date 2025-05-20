//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 1024

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Your password is too short. Minimum 8 characters required.\n");
    }
    else if (password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Your password is too long. Maximum %d characters allowed.\n", MAX_PASSWORD_LENGTH);
    }
    else
    {
        int strength = 0;

        for (int i = 0; i < password_length; i++)
        {
            if (isupper(password[i]))
            {
                strength++;
            }
            else if (islower(password[i]))
            {
                strength++;
            }
            else if (isdigit(password[i]))
            {
                strength++;
            }
            else if (ispunct(password[i]))
            {
                strength++;
            }
        }

        if (strength < 3)
        {
            printf("Your password is weak. Please use a stronger password.\n");
        }
        else
        {
            printf("Your password is strong.\n");
        }
    }

    return 0;
}