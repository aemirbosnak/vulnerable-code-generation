//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20

typedef struct PasswordStrengthChecker
{
    char password[PASSWORD_LENGTH];
    int strength;
    char message[100];
} PasswordStrengthChecker;

void calculateStrength(PasswordStrengthChecker *psc)
{
    int i, score = 0, hasUppercase = 0, hasLowercase = 0, hasNumber = 0, hasSymbol = 0;

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (psc->password[i] >= 'a' && psc->password[i] <= 'z')
            hasLowercase = 1;
        else if (psc->password[i] >= 'A' && psc->password[i] <= 'Z')
            hasUppercase = 1;
        else if (psc->password[i] >= '0' && psc->password[i] <= '9')
            hasNumber = 1;
        else if (psc->password[i] >= '!' && psc->password[i] <= '/')
            hasSymbol = 1;
    }

    if (hasUppercase && hasLowercase && hasNumber && hasSymbol)
        score = 5;
    else if (hasUppercase || hasLowercase || hasNumber || hasSymbol)
        score = 3;
    else
        score = 1;

    psc->strength = score;
    sprintf(psc->message, "Password strength: %d", score);
}

int main()
{
    PasswordStrengthChecker psc;

    printf("Enter your password: ");
    scanf("%s", psc.password);

    calculateStrength(&psc);

    printf("%s\n", psc.message);

    return 0;
}