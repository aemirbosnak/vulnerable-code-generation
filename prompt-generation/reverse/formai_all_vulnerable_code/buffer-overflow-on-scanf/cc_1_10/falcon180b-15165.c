//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int length, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 6)
    {
        printf("Password is too short.\n");
        return 1;
    }

    if (!isalpha(password[0]))
    {
        printf("Password must start with a letter.\n");
        return 1;
    }

    if (!isdigit(password[length - 1]))
    {
        printf("Password must end with a number.\n");
        return 1;
    }

    if (!isalnum(password[length - 2]))
    {
        printf("Password must have at least one special character.\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            score += 2;
        }
        else if (islower(password[i]))
        {
            score += 1;
        }
        else if (isdigit(password[i]))
        {
            score += 3;
        }
        else
        {
            score += 4;
        }
    }

    printf("Password strength: %d\n", score);

    return 0;
}