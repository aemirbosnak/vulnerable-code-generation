//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[256];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            strength++;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            strength++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            strength++;
        }
        else if (password[i] == '$' || password[i] == '#' || password[i] == '%')
        {
            strength++;
        }
    }

    switch (strength)
    {
        case 0:
            printf("Your password is extremely weak. Please choose a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case 2:
            printf("Your password is moderately strong. It meets the minimum requirements.\n");
            break;
        case 3:
            printf("Your password is strong. It is difficult to crack.\n");
            break;
        case 4:
            printf("Your password is very strong. It is extremely difficult to crack.\n");
            break;
    }

    return 0;
}