//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define PASSWORD_LENGTH 20

int main()
{
    char password[PASSWORD_LENGTH];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < PASSWORD_LENGTH; i++)
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
    }

    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please choose a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case 2:
            printf("Your password is fair. It could be stronger.\n");
            break;
        case 3:
            printf("Your password is good. It is strong, but could be better.\n");
            break;
        case 4:
            printf("Your password is strong. It is very difficult to crack.\n");
            break;
        default:
            printf("Error. Invalid password length.\n");
    }

    return 0;
}