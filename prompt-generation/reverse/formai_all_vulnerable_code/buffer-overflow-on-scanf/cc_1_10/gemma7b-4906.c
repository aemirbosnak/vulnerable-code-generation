//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20

int main()
{
    char password[PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    int strength = password_strength(password);

    switch (strength)
    {
        case 0:
            printf("Password is extremely weak.\n");
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
        case 5:
            printf("Password is extremely strong.\n");
            break;
    }

    return 0;
}

int password_strength(char *password)
{
    int strength = 0;

    // Check for minimum length
    if (strlen(password) < PASSWORD_LENGTH)
    {
        strength--;
    }

    // Check for uppercase letters
    if (!strchr(password, 'A'))
    {
        strength--;
    }

    // Check for lowercase letters
    if (!strchr(password, 'a'))
    {
        strength--;
    }

    // Check for numbers
    if (!strchr(password, '0'))
    {
        strength--;
    }

    // Check for special characters
    if (!strchr(password, '!'))
    {
        strength--;
    }

    return strength;
}