//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 16

void validate_password(char *password)
{
    int i, strength = 0;
    char lower, upper, number, symbol;

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            lower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            upper = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            number = 1;
        else if (password[i] >= '`' && password[i] <= '~')
            symbol = 1;
    }

    if (lower && upper && number && symbol)
        strength = 5;
    else if (lower || upper || number || symbol)
        strength = 3;
    else
        strength = 1;

    switch (strength)
    {
        case 5:
            printf("Strength: Excellent - You're a master of passwords.\n");
            break;
        case 3:
            printf("Strength: Good - You're doing well.\n");
            break;
        case 1:
            printf("Strength: Weak - Please try again.\n");
            break;
    }
}

int main()
{
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    validate_password(password);

    return 0;
}