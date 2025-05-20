//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWD_LEN 255

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int i, strength = 0, min_length = 0, has_upper = 0, has_number = 0, has_symbol = 0;

    printf("Let's see how strong your password is! Please enter your password: ");
    scanf("%s", passwd);

    // Minimum length check
    if (strlen(passwd) < 8)
    {
        min_length = 1;
        strength = 2;
    }
    else if (strlen(passwd) >= 8 && strlen(passwd) < 12)
    {
        min_length = 2;
        strength = 3;
    }
    else if (strlen(passwd) >= 12)
    {
        min_length = 3;
        strength = 4;
    }

    // Uppercase letter check
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= 'A' && passwd[i] <= 'Z')
        {
            has_upper = 1;
        }
    }

    // Number check
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= '0' && passwd[i] <= '9')
        {
            has_number = 1;
        }
    }

    // Symbol check
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= '!' && passwd[i] <= '~')
        {
            has_symbol = 1;
        }
    }

    // Strength calculation
    if (has_upper && has_number && has_symbol)
    {
        strength = 5;
    }
    else if (has_upper || has_number || has_symbol)
    {
        strength = 4;
    }
    else
    {
        strength = 3;
    }

    // Strength display
    switch (strength)
    {
        case 5:
            printf("Your password is extremely strong!\n");
            break;
        case 4:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is acceptable.\n");
            break;
        case 2:
            printf("Your password is weak. Please choose a longer password.\n");
            break;
        case 1:
            printf("Your password is very weak. Please choose a longer and more complex password.\n");
            break;
    }

    return 0;
}