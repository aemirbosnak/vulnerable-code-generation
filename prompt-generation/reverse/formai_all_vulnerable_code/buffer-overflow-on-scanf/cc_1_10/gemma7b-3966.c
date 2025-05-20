//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char password[20];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch (strength)
    {
        case 0:
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Your password is fair. You could improve it.\n");
            break;
        case 2:
            printf("Your password is good. It meets the recommended criteria.\n");
            break;
        case 3:
            printf("Your password is strong. It is very difficult to crack.\n");
            break;
        default:
            printf("Error: invalid password strength.\n");
    }

    return;
}

int check_password_strength(char *password)
{
    int length = strlen(password);
    int has_number = 0;
    int has_letter = 0;
    int has_symbol = 0;

    for (int i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
        {
            has_number = 1;
        }
        else if (isalpha(password[i]))
        {
            has_letter = 1;
        }
        else if (ispunct(password[i]))
        {
            has_symbol = 1;
        }
    }

    if (length < 8)
    {
        return 0;
    }
    else if (has_number && has_letter)
    {
        return 2;
    }
    else if (has_number || has_letter)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}