//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[30];
    int length, i, upper = 0, lower = 0, digit = 0, symbol = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check password length
    if (length < 8)
        printf("Your password is too short. It must be at least 8 characters long.\n");
    else
        printf("Your password length is okay.\n");

    // Check password characters
    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            upper++;
        else if (islower(password[i]))
            lower++;
        else if (isdigit(password[i]))
            digit++;
        else
            symbol++;
    }

    // Check uppercase letters
    if (upper == 0)
        printf("Your password needs at least one uppercase letter.\n");
    else
        printf("Your password has uppercase letter(s).\n");

    // Check lowercase letters
    if (lower == 0)
        printf("Your password needs at least one lowercase letter.\n");
    else
        printf("Your password has lowercase letter(s).\n");

    // Check digits
    if (digit == 0)
        printf("Your password needs at least one digit.\n");
    else
        printf("Your password has digit(s).\n");

    // Check symbols
    if (symbol == 0)
        printf("Your password needs at least one symbol.\n");
    else
        printf("Your password has symbol(s).\n");

    return 0;
}