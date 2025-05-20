//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, upper, lower, digits, special;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i=0; i<length; i++)
    {
        if (isupper(password[i]))
        {
            upper++;
        }
        else if (islower(password[i]))
        {
            lower++;
        }
        else if (isdigit(password[i]))
        {
            digits++;
        }
        else
        {
            special++;
        }
    }

    if (length < 8)
    {
        printf("Your password is weak.\nStrength: %d\n", strength);
        return 0;
    }

    if (upper > 0)
    {
        strength += 10;
    }
    if (lower > 0)
    {
        strength += 10;
    }
    if (digits > 0)
    {
        strength += 10;
    }
    if (special > 0)
    {
        strength += 10;
    }
    if (length >= 12)
    {
        strength += 10;
    }

    printf("Your password is ");

    if (strength >= 80)
    {
        printf("very strong.");
    }
    else if (strength >= 50)
    {
        printf("strong.");
    }
    else if (strength >= 30)
    {
        printf("moderate.");
    }
    else
    {
        printf("weak.");
    }

    printf("\nStrength: %d\n", strength);

    return 0;
}