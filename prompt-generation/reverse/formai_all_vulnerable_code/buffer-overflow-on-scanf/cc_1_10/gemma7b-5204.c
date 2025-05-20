//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pwstrength(char *pw)
{
    int strength = 0;
    int i = 0;

    for (; pw[i] != '\0'; i++)
    {
        if (pw[i] >= 'a' && pw[i] <= 'z')
            strength++;
        else if (pw[i] >= 'A' && pw[i] <= 'Z')
            strength++;
        else if (pw[i] >= '0' && pw[i] <= '9')
            strength++;
        else if (pw[i] == '$' || pw[i] == '#' || pw[i] == '%')
            strength++;
    }

    if (strength < 6)
    {
        return pwstrength(pw);
    }
    else
    {
        return strength;
    }
}

int main()
{
    char pw[20];

    printf("Enter your password: ");
    scanf("%s", pw);

    int strength = pwstrength(pw);

    if (strength >= 6)
    {
        printf("Your password is strong.\n");
    }
    else
    {
        printf("Your password is weak. Please try again.\n");
    }

    return 0;
}