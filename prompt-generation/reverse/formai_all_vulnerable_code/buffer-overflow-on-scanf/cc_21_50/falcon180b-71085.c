//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length = 0, upper = 0, lower = 0, digit = 0, special = 0;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            upper = 1;
        }
        else if (islower(password[i]))
        {
            lower = 1;
        }
        else if (isdigit(password[i]))
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }
    }

    if (length < 8)
    {
        printf("Password is too short.\n");
    }
    else if (!upper &&!lower &&!digit &&!special)
    {
        printf("Password is too weak.\n");
    }
    else if (!upper ||!lower ||!digit ||!special)
    {
        printf("Password is weak.\n");
    }
    else if (length >= 12 && upper && lower && digit && special)
    {
        printf("Password is strong.\n");
        strength = 5;
    }
    else if (length >= 12 && (upper || lower) && (digit || special))
    {
        printf("Password is medium.\n");
        strength = 3;
    }
    else if (length >= 8 && upper && lower)
    {
        printf("Password is fair.\n");
        strength = 2;
    }
    else
    {
        printf("Password is poor.\n");
        strength = 1;
    }

    return 0;
}