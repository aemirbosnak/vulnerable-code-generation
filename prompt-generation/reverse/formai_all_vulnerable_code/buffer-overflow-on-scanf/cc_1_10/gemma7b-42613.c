//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void password_strength(char *pass)
{
    int strength = 0;
    int min_length = 8;
    int has_upper = 0;
    int has_number = 0;
    int has_symbol = 0;

    if (strlen(pass) >= min_length)
    {
        strength++;
    }

    for (int i = 0; i < strlen(pass); i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            has_upper = 1;
            strength++;
        }
        else if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            has_upper = 1;
            strength++;
        }
        else if (pass[i] >= '0' && pass[i] <= '9')
        {
            has_number = 1;
            strength++;
        }
        else if (pass[i] >= '!' && pass[i] <= '/')
        {
            has_symbol = 1;
            strength++;
        }
    }

    switch (strength)
    {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderately strong.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
    }

    if (has_upper && has_number && has_symbol)
    {
        printf("It is recommended to change your password.\n");
    }
}

int main()
{
    char pass[256];

    printf("Enter your password: ");
    scanf("%s", pass);

    password_strength(pass);

    return 0;
}