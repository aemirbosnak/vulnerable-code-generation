//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the length of the password
    password_length = strlen(password);

    // Check if the password is strong
    if (password_length >= 8 && password_length <= MAX_PASSWORD_LENGTH)
    {
        int has_upper_case = 0;
        int has_lower_case = 0;
        int has_number = 0;
        int has_symbol = 0;

        // Check if the password has any upper case letters
        for (int i = 0; i < password_length; i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                has_upper_case = 1;
            }
        }

        // Check if the password has any lower case letters
        for (int i = 0; i < password_length; i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                has_lower_case = 1;
            }
        }

        // Check if the password has any numbers
        for (int i = 0; i < password_length; i++)
        {
            if (password[i] >= '0' && password[i] <= '9')
            {
                has_number = 1;
            }
        }

        // Check if the password has any symbols
        for (int i = 0; i < password_length; i++)
        {
            if (password[i] >= '!' && password[i] <= '~')
            {
                has_symbol = 1;
            }
        }

        // Check if the password has all of the above criteria
        if (has_upper_case && has_lower_case && has_number && has_symbol)
        {
            printf("Your password is strong.\n");
        }
        else
        {
            printf("Your password is not strong. Please use a stronger password.\n");
        }
    }
    else
    {
        printf("Your password is not strong. Please use a longer password.\n");
    }

    return 0;
}