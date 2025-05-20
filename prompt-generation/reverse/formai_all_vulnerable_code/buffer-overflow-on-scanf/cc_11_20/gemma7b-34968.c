//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[256];
    int i, strength = 0, length = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++)
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
        else
        {
            strength--;
        }
    }

    switch (strength)
    {
        case 0:
            printf("Password is very weak.\n");
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

    return 0;
}