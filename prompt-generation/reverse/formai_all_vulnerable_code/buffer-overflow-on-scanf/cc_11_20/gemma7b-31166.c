//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20

char password_strength(char *password)
{
    int strength = 0;
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++)
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
            return 'F';
        case 1:
            return 'P';
        case 2:
            return 'G';
        case 3:
            return 'S';
        case 4:
            return 'A';
    }
}

int main()
{
    char password[PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    char strength = password_strength(password);

    switch (strength)
    {
        case 'F':
            printf("Password is too weak.\n");
            break;
        case 'P':
            printf("Password is poor.\n");
            break;
        case 'G':
            printf("Password is good.\n");
            break;
        case 'S':
            printf("Password is strong.\n");
            break;
        case 'A':
            printf("Password is excellent.\n");
            break;
    }

    return 0;
}