//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, hasUppercase = 0, hasNumber = 0, hasSymbol = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
            hasUppercase = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
            hasUppercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
            hasNumber = 1;
        }
        else if (password[i] >= '!' && password[i] <= '~')
        {
            strength++;
            hasSymbol = 1;
        }
    }

    switch (strength)
    {
        case 0:
            printf("Password is too weak!\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
    }

    if (hasUppercase && hasNumber && hasSymbol)
    {
        printf("Your password has all the recommended criteria.\n");
    }

    return 0;
}