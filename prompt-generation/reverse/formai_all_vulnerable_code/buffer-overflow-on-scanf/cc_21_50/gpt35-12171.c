//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Cyberpunk Password Strength Checker */

int main()
{
    char password[50];
    int length, upper_case, lower_case, digits, symbols, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    /* Check for length */
    if (length >= 10 && length <= 20)
        score++;

    /* Check for uppercase letters */
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            upper_case = 1;
    }

    if (upper_case)
        score++;

    /* Check for lowercase letters */
    for (int i = 0; i < length; i++)
    {
        if (islower(password[i]))
            lower_case = 1;
    }

    if (lower_case)
        score++;

    /* Check for digits */
    for (int i = 0; i < length; i++)
    {
        if (isdigit(password[i]))
            digits = 1;
    }

    if (digits)
        score++;

    /* Check for symbols */
    for (int i = 0; i < length; i++)
    {
        if (!isalnum(password[i]))
            symbols = 1;
    }

    if (symbols)
        score++;

    /* Print score and feedback */
    printf("\n==========\n\n");
    printf("Your password strength score is %d/5.\n\n", score);

    switch (score)
    {
        case 0:
            printf("Pathetic. You call this a password?\n\n");
            break;
        case 1:
            printf("Oh come on, is that the best you can do?\n\n");
            break;
        case 2:
            printf("Not bad, but you can do better.\n\n");
            break;
        case 3:
            printf("Impressive, but still room for improvement.\n\n");
            break;
        case 4:
            printf("Excellent job, that's a strong password!\n\n");
            break;
        case 5:
            printf("A true cyberpunk password. You're on fire!\n\n");
            break;
    }

    return 0;
}