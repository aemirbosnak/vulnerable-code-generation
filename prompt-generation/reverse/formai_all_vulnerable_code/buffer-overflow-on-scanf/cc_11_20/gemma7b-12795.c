//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWD_LENGTH 255

int main()
{
    char password[MAX_PASSWD_LENGTH];
    int i, strength, min_upper, min_num, min_sym;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = 0;
    min_upper = 0;
    min_num = 0;
    min_sym = 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        // Uppercase letter
        if (isupper(password[i]))
            min_upper = 1;

        // Number
        if (isdigit(password[i]))
            min_num = 1;

        // Symbol
        if (ispunct(password[i]))
            min_sym = 1;
    }

    if (min_upper && min_num && min_sym)
    {
        strength = 3;
    }
    else if (min_upper || min_num || min_sym)
    {
        strength = 2;
    }
    else
    {
        strength = 1;
    }

    switch (strength)
    {
        case 3:
            printf("Your password is very strong.\n");
            break;
        case 2:
            printf("Your password is strong, but could be improved.\n");
            break;
        case 1:
            printf("Your password is weak, please choose a stronger one.\n");
            break;
    }

    return 0;
}