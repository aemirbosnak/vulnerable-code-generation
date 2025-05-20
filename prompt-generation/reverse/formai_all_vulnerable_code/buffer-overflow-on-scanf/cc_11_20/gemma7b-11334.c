//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, min_length = 8, max_length = 16;

    printf("Enter your password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;
        else if (password[i] >= '0' && password[i] <= '9')
            strength++;
        else
            strength--;
    }

    if (strlen(password) < min_length || strlen(password) > max_length)
    {
        strength = strength - 2;
    }

    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please try again.\n");
            break;
        case 1:
            printf("Your password is weak. Please try again.\n");
            break;
        case 2:
            printf("Your password is fair. It could be better.\n");
            break;
        case 3:
            printf("Your password is good. It is difficult to guess.\n");
            break;
        case 4:
            printf("Your password is strong. It is very difficult to guess.\n");
            break;
        default:
            printf("Your password is invalid. Please try again.\n");
            break;
    }

    return 0;
}