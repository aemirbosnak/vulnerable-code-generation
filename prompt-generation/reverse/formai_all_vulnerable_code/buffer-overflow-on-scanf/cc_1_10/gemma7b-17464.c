//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWD_LENGTH 255

void passwordStrength(char *passwd)
{
    int passwordLength = strlen(passwd);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSymbol = 0;

    for (int i = 0; i < passwordLength; i++)
    {
        if (passwd[i] >= 'A' && passwd[i] <= 'Z')
        {
            hasUppercase = 1;
        }
        else if (passwd[i] >= 'a' && passwd[i] <= 'z')
        {
            hasLowercase = 1;
        }
        else if (passwd[i] >= '0' && passwd[i] <= '9')
        {
            hasNumber = 1;
        }
        else if (passwd[i] >= '!' && passwd[i] <= '~')
        {
            hasSymbol = 1;
        }
    }

    int strength = (hasUppercase && hasLowercase) ? 2 : 1;
    strength += hasNumber ? 1 : 0;
    strength += hasSymbol ? 1 : 0;

    switch (strength)
    {
        case 3:
            printf("Strength: Very Strong\n");
            break;
        case 2:
            printf("Strength: Strong\n");
            break;
        case 1:
            printf("Strength: Weak\n");
            break;
        default:
            printf("Strength: Invalid\n");
            break;
    }
}

int main()
{
    char passwd[MAX_PASSWD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", passwd);

    passwordStrength(passwd);

    return 0;
}