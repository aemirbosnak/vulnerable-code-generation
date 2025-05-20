//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrength
{
    int strength;
    char *message;
} PasswordStrength;

PasswordStrength checkPasswordStrength(char *password)
{
    PasswordStrength ps;
    ps.strength = 0;
    ps.message = malloc(100);

    if (strlen(password) < 8)
    {
        strcpy(ps.message, "Password too short!");
        return ps;
    }

    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumbers = 0;
    int hasSymbols = 0;

    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
            hasUppercase = 1;
        else if (islower(password[i]))
            hasLowercase = 1;
        else if (isdigit(password[i]))
            hasNumbers = 1;
        else if (ispunct(password[i]))
            hasSymbols = 1;
    }

    if (hasUppercase && hasLowercase && hasNumbers && hasSymbols)
    {
        ps.strength = 5;
        strcpy(ps.message, "Very strong password!");
    }
    else if (hasUppercase || hasLowercase || hasNumbers || hasSymbols)
    {
        ps.strength = 3;
        strcpy(ps.message, "Strong password!");
    }
    else
    {
        ps.strength = 1;
        strcpy(ps.message, "Weak password!");
    }

    return ps;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength ps = checkPasswordStrength(password);

    printf("Password strength: %d\n", ps.strength);
    printf("Message: %s\n", ps.message);

    return 0;
}