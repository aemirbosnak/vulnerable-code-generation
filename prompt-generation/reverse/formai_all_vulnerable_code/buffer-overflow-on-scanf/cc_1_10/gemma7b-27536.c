//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrengthChecker
{
    char password[MAX_PASSWORD_LENGTH];
    int strength;
    char message[256];
} PasswordStrengthChecker;

void calculatePasswordStrength(PasswordStrengthChecker *psc)
{
    int i, passwordLength = strlen(psc->password);

    psc->strength = 0;

    for (i = 0; i < passwordLength; i++)
    {
        if (isupper(psc->password[i]))
            psc->strength++;
        else if (islower(psc->password[i]))
            psc->strength++;
        else if (isdigit(psc->password[i]))
            psc->strength++;
        else if (ispunct(psc->password[i]))
            psc->strength++;
    }

    switch (psc->strength)
    {
        case 0:
            strcpy(psc->message, "Weak");
            break;
        case 1:
            strcpy(psc->message, "Fair");
            break;
        case 2:
            strcpy(psc->message, "Good");
            break;
        case 3:
            strcpy(psc->message, "Strong");
            break;
        case 4:
            strcpy(psc->message, "Excellent");
            break;
    }
}

int main()
{
    PasswordStrengthChecker pscc;

    printf("Enter your password: ");
    scanf("%s", pscc.password);

    calculatePasswordStrength(&pscc);

    printf("Your password strength is: %s\n", pscc.message);

    return 0;
}