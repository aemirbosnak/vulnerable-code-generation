//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int passwordStrength(char *pass)
{
    int strength = 0;
    char lower = 0, upper = 0, num = 0, special = 0;

    if (*pass == '\0')
    {
        return strength;
    }

    if (*pass >= 'a' && *pass <= 'z')
    {
        lower = 1;
    }
    else if (*pass >= 'A' && *pass <= 'Z')
    {
        upper = 1;
    }
    else if (*pass >= '0' && *pass <= '9')
    {
        num = 1;
    }
    else if (*pass >= '`' && *pass <= '~')
    {
        special = 1;
    }

    strength += lower + upper + num + special;

    return passwordStrength(pass + 1) + strength;
}

int main()
{
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = passwordStrength(password);

    switch (strength)
    {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderate.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}