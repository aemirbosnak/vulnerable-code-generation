//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    if (strlen(password) < 8)
    {
        printf("Password too short.\n");
    }
    else if (strcmp(password, "password") == 0)
    {
        printf("Password too weak.\n");
    }
    else if (hasUppercase(password) && hasNumber(password))
    {
        printf("Strong password.\n");
    }
    else
    {
        printf("Password not strong.\n");
    }

    return 0;
}

int hasUppercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            return 1;
        }
    }

    return 0;
}

int hasNumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            return 1;
        }
    }

    return 0;
}