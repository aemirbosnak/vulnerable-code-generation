//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;
    int has_upper = 0;
    int has_number = 0;
    int has_symbol = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    for (int i = 0; i < password_length; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = 1;
        }
        else if (isdigit(password[i]))
        {
            has_number = 1;
        }
        else if (ispunct(password[i]))
        {
            has_symbol = 1;
        }
    }

    if (has_upper && has_number && has_symbol)
    {
        strength = 5;
    }
    else if (has_upper || has_number || has_symbol)
    {
        strength = 3;
    }
    else
    {
        strength = 1;
    }

    switch (strength)
    {
        case 5:
            printf("Your password is very strong!\n");
            break;
        case 3:
            printf("Your password is strong, but could be improved.\n");
            break;
        case 1:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
    }

    return 0;
}