//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for minimum length
    if (password_length < 8)
    {
        strength -= 1;
        printf("Password too short. Minimum 8 characters required.\n");
    }

    // Check for uppercase letter
    if (!strchr(password, toupper(rand() % 26)))
    {
        strength -= 1;
        printf("Password lacks uppercase letter.\n");
    }

    // Check for lowercase letter
    if (!strchr(password, tolower(rand() % 26)))
    {
        strength -= 1;
        printf("Password lacks lowercase letter.\n");
    }

    // Check for number
    if (!strchr(password, rand() % 10 + '0'))
    {
        strength -= 1;
        printf("Password lacks number.\n");
    }

    // Check for special character
    if (!strchr(password, rand() % 32 + 32))
    {
        strength -= 1;
        printf("Password lacks special character.\n");
    }

    // Display strength
    switch (strength)
    {
        case 5:
            printf("Password is very strong.\n");
            break;
        case 4:
            printf("Password is strong.\n");
            break;
        case 3:
            printf("Password is moderate.\n");
            break;
        case 2:
            printf("Password is weak.\n");
            break;
        case 1:
            printf("Password is very weak.\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }

    return 0;
}