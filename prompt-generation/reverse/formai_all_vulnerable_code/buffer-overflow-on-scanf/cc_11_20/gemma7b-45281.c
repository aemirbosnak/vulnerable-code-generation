//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LEN 255

int main()
{
    char pass[MAX_PASS_LEN];
    int i, strength = 0, hasUppercase = 0, hasLowercase = 0, hasNumber = 0, hasSymbol = 0;

    printf("Let's crack that password!\n");
    printf("Enter your password: ");

    scanf("%s", pass);

    for (i = 0; pass[i] != '\0'; i++)
    {
        if (isupper(pass[i]))
        {
            hasUppercase = 1;
        }
        else if (islower(pass[i]))
        {
            hasLowercase = 1;
        }
        else if (isdigit(pass[i]))
        {
            hasNumber = 1;
        }
        else if (ispunct(pass[i]))
        {
            hasSymbol = 1;
        }
    }

    if (hasUppercase && hasLowercase && hasNumber && hasSymbol)
    {
        strength = 5;
    }
    else if (hasUppercase || hasLowercase || hasNumber || hasSymbol)
    {
        strength = 3;
    }
    else
    {
        strength = 1;
    }

    switch (strength)
    {
        case 5:
            printf("Your password is very strong!\n");
            break;
        case 3:
            printf("Your password is somewhat weak. Please consider changing it.\n");
            break;
        case 1:
            printf("Your password is extremely weak. Please change it immediately!\n");
            break;
    }

    return 0;
}