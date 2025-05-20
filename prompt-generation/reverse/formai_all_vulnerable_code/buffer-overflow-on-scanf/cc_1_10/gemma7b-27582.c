//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWD_LENGTH 255

int main()
{
    char password[MAX_PASSWD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    int password_strength = check_password_strength(password);

    switch (password_strength)
    {
        case 0:
            printf("Password is too weak.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
        default:
            printf("Error.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password)
{
    int password_length = strlen(password);

    // Minimum password length
    if (password_length < 8)
    {
        return 0;
    }

    // Presence of uppercase letter
    if (!strchr(password, 'A') && !strchr(password, 'a'))
    {
        return 1;
    }

    // Presence of lowercase letter
    if (!strchr(password, 'A') && !strchr(password, 'a'))
    {
        return 1;
    }

    // Presence of number
    if (!strchr(password, '0') && !strchr(password, '9'))
    {
        return 1;
    }

    // Presence of special character
    if (!strchr(password, '!'))
    {
        return 1;
    }

    // Strong password
    return 4;
}