//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 20

int main()
{
    char password[PASSWORD_MAX_LENGTH];
    int password_length;

    printf("Enter a password: ");
    scanf("%s", password);

    password_length = strlen(password);

    if (password_length < PASSWORD_MIN_LENGTH || password_length > PASSWORD_MAX_LENGTH)
    {
        printf("Error: Password must be between %d and %d characters long.\n", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
    }
    else
    {
        int strong = 0;
        for (int i = 0; i < password_length; i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                strong++;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z')
            {
                strong++;
            }
            else if (password[i] >= '0' && password[i] <= '9')
            {
                strong++;
            }
            else if (password[i] == '$' || password[i] == '#' || password[i] == '%')
            {
                strong++;
            }
        }

        if (strong >= 3)
        {
            printf("Strong password.\n");
        }
        else
        {
            printf("Weak password.\n");
        }
    }

    return 0;
}