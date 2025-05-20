//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrength
{
    int score;
    char *message;
} PasswordStrength;

PasswordStrength check_password_strength(char *password)
{
    PasswordStrength strength = { 0, NULL };

    if (strlen(password) < 8)
    {
        strength.score = 1;
        strength.message = "Password too short";
    }
    else if (strlen(password) < 12)
    {
        strength.score = 2;
        strength.message = "Password could be stronger";
    }
    else if (strlen(password) < 16)
    {
        strength.score = 3;
        strength.message = "Good password";
    }
    else
    {
        strength.score = 4;
        strength.message = "Strong password";
    }

    return strength;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    PasswordStrength strength = check_password_strength(password);

    switch (strength.score)
    {
        case 1:
            printf("Password too short. Please use at least 8 characters.\n");
            break;
        case 2:
            printf("Password could be stronger. Please use more characters or special symbols.\n");
            break;
        case 3:
            printf("Good password. You can use this password.\n");
            break;
        case 4:
            printf("Strong password. You are safe.\n");
            break;
    }

    return 0;
}