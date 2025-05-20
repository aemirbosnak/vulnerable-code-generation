//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrength
{
    int strength;
    char message[255];
} PasswordStrength;

PasswordStrength checkPasswordStrength(char *password)
{
    PasswordStrength ps = {0, ""};

    // Check for minimum length
    if (strlen(password) < 8)
    {
        ps.strength = 1;
        sprintf(ps.message, "Password too short. Minimum 8 characters required.");
    }

    // Check for uppercase letter
    else if (!strchr(password, 'A') && !strchr(password, 'a'))
    {
        ps.strength = 2;
        sprintf(ps.message, "Password lacks uppercase letter.");
    }

    // Check for lowercase letter
    else if (!strchr(password, 'a') && !strchr(password, 'A'))
    {
        ps.strength = 3;
        sprintf(ps.message, "Password lacks lowercase letter.");
    }

    // Check for number
    else if (!strchr(password, '0') && !strchr(password, '9'))
    {
        ps.strength = 4;
        sprintf(ps.message, "Password lacks number.");
    }

    // Check for special character
    else if (!strchr(password, '$') && !strchr(password, '^') &&
        !strchr(password, '&') && !strchr(password, '*'))
    {
        ps.strength = 5;
        sprintf(ps.message, "Password lacks special character.");
    }

    // Strong password
    else
    {
        ps.strength = 6;
        sprintf(ps.message, "Password is strong.");
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