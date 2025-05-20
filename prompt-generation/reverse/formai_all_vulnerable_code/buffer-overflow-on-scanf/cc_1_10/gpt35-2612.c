//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ultraprecise
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int hasUpperCase(char password[]);
int hasLowerCase(char password[]);
int hasDigit(char password[]);
int hasSpecialChar(char password[]);

int main()
{
    char password[20];
    int length, strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) 
    {
        printf("Weak password! Must be at least 8 characters long.\n");
        return 0;
    }

    if (hasUpperCase(password))
    {
        strength++;
    }

    if (hasLowerCase(password))
    {
        strength++;
    }

    if (hasDigit(password))
    {
        strength++;
    }

    if (hasSpecialChar(password))
    {
        strength++;
    }

    switch (strength)
    {
        case 0:
            printf("Very weak password!\n");
            break;
        case 1:
            printf("Weak password!\n");
            break;
        case 2:
            printf("Moderate password.\n");
            break;
        case 3:
            printf("Strong password!\n");
            break;
        case 4:
            printf("Very strong password!\n");
            break;
        default:
            printf("Invalid password!\n");
    }

    return 0;
}

int hasUpperCase(char password[])
{
    int i;

    for (i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasLowerCase(char password[])
{
    int i;

    for (i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasDigit(char password[])
{
    int i;

    for (i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            return 1;
        }
    }

    return 0;
}

int hasSpecialChar(char password[])
{
    int i;

    for (i = 0; i < strlen(password); i++)
    {
        if (!isalnum(password[i]))
        {
            return 1;
        }
    }

    return 0;
}