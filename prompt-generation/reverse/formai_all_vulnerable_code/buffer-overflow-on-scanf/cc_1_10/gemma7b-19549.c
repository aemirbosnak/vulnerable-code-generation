//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

void password_strength(char *password)
{
    int password_length = strlen(password);
    int has_upper = 0, has_lower = 0, has_number = 0, has_symbol = 0;

    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            has_upper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            has_lower = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            has_number = 1;
        else if (password[i] >= '!' && password[i] <= '~')
            has_symbol = 1;
    }

    int strength = (has_upper) ? 1 : 0;
    strength += (has_lower) ? 1 : 0;
    strength += (has_number) ? 1 : 0;
    strength += (has_symbol) ? 1 : 0;

    switch (strength)
    {
        case 0:
            printf("Password is too weak. Please use at least one character from the following categories:\n"
                   "Uppercase letters, Lowercase letters, Numbers, Symbols\n");
            break;
        case 1:
            printf("Password is weak. Please use at least two characters from the following categories:\n"
                   "Uppercase letters, Lowercase letters, Numbers, Symbols\n");
            break;
        case 2:
            printf("Password is good. Please use at least three characters from the following categories:\n"
                   "Uppercase letters, Lowercase letters, Numbers, Symbols\n");
            break;
        case 3:
            printf("Password is strong. Please use at least four characters from the following categories:\n"
                   "Uppercase letters, Lowercase letters, Numbers, Symbols\n");
            break;
        case 4:
            printf("Password is very strong. You have used all the categories!\n");
            break;
    }
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    password_strength(password);

    return 0;
}