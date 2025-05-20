//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASS_LENGTH 255

int validate_password(char *pass)
{
    int strength = 0;
    int min_length = 8;
    char *special_chars = "$#@!%*()";

    if (strlen(pass) < min_length)
    {
        return strength;
    }

    for (int i = 0; i < strlen(pass); i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            strength++;
        }
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            strength++;
        }
        else if (pass[i] >= '0' && pass[i] <= '9')
        {
            strength++;
        }
        else if (strchr(special_chars, pass[i]))
        {
            strength++;
        }
    }

    return strength;
}

int main()
{
    char pass[MAX_PASS_LENGTH];

    printf("Enter your password: ");
    scanf("%s", pass);

    int strength = validate_password(pass);

    switch (strength)
    {
        case 0:
            printf("Password is very weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Password is weak. Please use a stronger password.\n");
            break;
        case 2:
            printf("Password is moderate. It is acceptable, but could be stronger.\n");
            break;
        case 3:
            printf("Password is strong. It meets all the criteria.\n");
            break;
        default:
            printf("Invalid password. Please try again.\n");
            break;
    }

    return 0;
}