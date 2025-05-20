//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LEN 255

int main()
{
    char password[MAX_PASSWORD_LEN];
    int strength = 0;
    int i;

    printf("Enter a password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isalnum(password[i]))
        {
            strength++;
        }
        else if (isupper(password[i]))
        {
            strength++;
        }
        else if (islower(password[i]))
        {
            strength++;
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