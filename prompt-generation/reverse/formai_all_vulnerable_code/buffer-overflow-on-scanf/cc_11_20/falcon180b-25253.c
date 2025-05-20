//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL "!@#$%^&*()_+-=[]{}|;:,.<>?"

int main()
{
    char password[100];
    int length, i, j, uppercase = 0, lowercase = 0, numbers = 0, special = 0;
    srand(time(NULL));

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8)
    {
        printf("Sorry, your password is too short.\n");
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            uppercase = 1;
        }
        else if (islower(password[i]))
        {
            lowercase = 1;
        }
        else if (isdigit(password[i]))
        {
            numbers = 1;
        }
        else if (strchr(SPECIAL, password[i])!= NULL)
        {
            special = 1;
        }
    }

    if (uppercase && lowercase && numbers && special)
    {
        printf("Congratulations! Your password is very strong.\n");
    }
    else
    {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}