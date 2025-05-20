//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20

void passwordStrength(char *password)
{
    int strength = 0;
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasNumbers = 0;
    int hasSymbols = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowercase = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasNumbers = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            hasSymbols = 1;
        }
    }

    strength = hasLowercase + hasUppercase + hasNumbers + hasSymbols;

    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        default:
            printf("Invalid password\n");
            break;
    }
}

int main()
{
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    passwordStrength(password);

    return 0;
}