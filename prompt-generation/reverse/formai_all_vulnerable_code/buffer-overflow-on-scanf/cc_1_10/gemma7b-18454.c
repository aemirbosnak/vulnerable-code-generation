//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWD_LEN 255

int validatePassword(char *passwd)
{
    int strength = 0;
    int i;

    if (strlen(passwd) < 8)
    {
        strength = 0;
    }
    else if (strlen(passwd) >= 8 && strlen(passwd) < 16)
    {
        strength = 1;
    }
    else if (strlen(passwd) >= 16)
    {
        strength = 2;
    }

    for (i = 0; i < strlen(passwd); i++)
    {
        if (isupper(passwd[i]))
        {
            strength++;
        }
        else if (islower(passwd[i]))
        {
            strength++;
        }
        else if (isdigit(passwd[i]))
        {
            strength++;
        }
        else if (ispunct(passwd[i]))
        {
            strength++;
        }
    }

    return strength;
}

int main()
{
    char passwd[MAX_PASSWD_LEN];

    printf("Enter your password: ");
    scanf("%s", passwd);

    int strength = validatePassword(passwd);

    switch (strength)
    {
        case 0:
            printf("Password too weak!\n");
            break;
        case 1:
            printf("Password acceptable.\n");
            break;
        case 2:
            printf("Password strong.\n");
            break;
    }

    return 0;
}