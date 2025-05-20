//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWD_LENGTH 128

int main()
{
    char password[MAX_PASSWD_LENGTH];
    int password_length = 0;
    int i = 0;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    for (i = 0; i < password_length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
        else if (password[i] == '$' || password[i] == '#' || password[i] == '%')
        {
            strength++;
        }
    }

    switch (strength)
    {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderate.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}