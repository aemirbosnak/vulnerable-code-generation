//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int password_strength(char *password, int length)
{
    int strength = 0;
    if (length < 8)
    {
        strength = -1;
    }
    else if (length >= 8 && length <= 16)
    {
        strength = 0;
    }
    else if (length > 16)
    {
        strength = 1;
    }

    if (strength == -1)
    {
        printf("Password too short!\n");
    }
    else if (strength == 0)
    {
        printf("Password acceptable.\n");
    }
    else if (strength == 1)
    {
        printf("Password strong.\n");
    }

    return strength;
}

int main()
{
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = password_strength(password, strlen(password));

    switch (strength)
    {
        case -1:
            printf("Password too short!\n");
            break;
        case 0:
            printf("Password acceptable.\n");
            break;
        case 1:
            printf("Password strong.\n");
            break;
    }

    return 0;
}