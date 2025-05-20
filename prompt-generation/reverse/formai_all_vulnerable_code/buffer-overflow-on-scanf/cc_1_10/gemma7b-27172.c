//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128

typedef struct PasswordStrength
{
    int strength;
    char message[MAX_PASSWORD_LENGTH];
} PasswordStrength;

PasswordStrength checkPasswordStrength(char *password)
{
    PasswordStrength strength = {0, ""};

    if (strlen(password) < 8)
    {
        strength.strength = 1;
        strcpy(strength.message, "Too short! Please use at least 8 characters.");
    }
    else if (strlen(password) < 16)
    {
        strength.strength = 2;
        strcpy(strength.message, "Weak! Use more characters.");
    }
    else if (strlen(password) < 24)
    {
        strength.strength = 3;
        strcpy(strength.message, "Good! Use a combination of uppercase and lowercase letters, numbers, and symbols.");
    }
    else
    {
        strength.strength = 4;
        strcpy(strength.message, "Strong! Use a combination of uppercase and lowercase letters, numbers, and symbols, and consider using a password manager.");
    }

    return strength;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength = checkPasswordStrength(password);

    printf("Password strength: %d\n", strength.strength);
    printf("Message: %s\n", strength.message);

    return 0;
}