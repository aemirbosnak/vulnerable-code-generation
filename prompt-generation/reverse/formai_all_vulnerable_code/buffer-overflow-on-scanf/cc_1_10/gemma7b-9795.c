//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWD_LENGTH 255

int main()
{
    char password[MAX_PASSWD_LENGTH];
    char *strength_indicator = "Weak";

    printf("Enter your password: ");
    scanf("%s", password);

    if (strlen(password) < 8)
    {
        strength_indicator = "Too Short";
    }
    else if (hasUppercase(password) && hasLowercase(password) && hasNumber(password))
    {
        strength_indicator = "Strong";
    }
    else
    {
        strength_indicator = "Weak";
    }

    printf("Password Strength: %s\n", strength_indicator);

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

int hasLowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
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