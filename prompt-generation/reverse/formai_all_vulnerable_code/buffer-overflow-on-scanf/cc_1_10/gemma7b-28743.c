//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrength
{
    int score;
    char message[256];
} PasswordStrength;

PasswordStrength check_password_strength(char *password)
{
    PasswordStrength strength;
    strength.score = 0;
    strength.message[0] = '\0';

    if (strlen(password) < 8)
    {
        strcat(strength.message, "Password must be at least 8 characters long.");
    }

    if (!isalnum(password[0]))
    {
        strcat(strength.message, "Password must contain an alphanumeric character.");
    }

    if (!isupper(password[0]))
    {
        strcat(strength.message, "Password must contain an uppercase letter.");
    }

    if (!islower(password[0]))
    {
        strcat(strength.message, "Password must contain a lowercase letter.");
    }

    if (strcmp(password, "abc") == 0)
    {
        strcat(strength.message, "Password is too weak, please use a different password.");
    }

    switch (strlen(password))
    {
        case 8:
            strength.score = 3;
            break;
        case 9:
            strength.score = 4;
            break;
        case 10:
            strength.score = 5;
            break;
        case 11:
            strength.score = 6;
            break;
        case 12:
            strength.score = 7;
            break;
        default:
            strength.score = 2;
            break;
    }

    return strength;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength = check_password_strength(password);

    if (strength.score >= 5)
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is not strong. Please change your password.\n");
        printf("Message: %s\n", strength.message);
    }

    return 0;
}