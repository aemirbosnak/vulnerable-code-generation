//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char password[256];
    int password_length;
    int strength = 0;

    printf("Enter password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length >= 8)
    {
        strength++;
    }

    if (hasUppercase(password))
    {
        strength++;
    }

    if (hasNumber(password))
    {
        strength++;
    }

    if (hasSymbol(password))
    {
        strength++;
    }

    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        default:
            printf("Password strength: Invalid\n");
            break;
    }

    return 0;
}

int hasUppercase(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            return 1;
        }
    }

    return 0;
}

int hasNumber(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            return 1;
        }
    }

    return 0;
}

int hasSymbol(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            return 1;
        }
    }

    return 0;
}