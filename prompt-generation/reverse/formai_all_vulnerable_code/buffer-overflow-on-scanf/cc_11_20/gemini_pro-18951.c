//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int length;
    int hasUpper;
    int hasLower;
    int hasDigit;
    int hasSpecial;
} PasswordStrength;

int main()
{
    char password[101];
    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength = {0, 0, 0, 0, 0};
    strength.length = strlen(password);

    for (int i = 0; i < strength.length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength.hasUpper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength.hasLower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            strength.hasDigit = 1;
        }
        else
        {
            strength.hasSpecial = 1;
        }
    }

    int score = 0;

    if (strength.length >= 8)
    {
        score += 1;
    }
    if (strength.hasUpper)
    {
        score += 1;
    }
    if (strength.hasLower)
    {
        score += 1;
    }
    if (strength.hasDigit)
    {
        score += 1;
    }
    if (strength.hasSpecial)
    {
        score += 1;
    }

    printf("Password strength: ");

    switch (score)
    {
    case 0:
        printf("Very weak");
        break;
    case 1:
        printf("Weak");
        break;
    case 2:
        printf("Medium");
        break;
    case 3:
        printf("Strong");
        break;
    case 4:
        printf("Very strong");
        break;
    case 5:
        printf("Excellent");
        break;
    default:
        printf("Invalid");
    }

    printf("\n");

    return 0;
}