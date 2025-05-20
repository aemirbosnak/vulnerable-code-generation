//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20

void check_password_strength(char *password)
{
    int strength = 0;
    char lowercase, uppercase, number, symbol;

    lowercase = password[0] >= 'a' && password[0] <= 'z';
    uppercase = password[0] >= 'A' && password[0] <= 'Z';
    number = password[0] >= '0' && password[0] <= '9';
    symbol = password[0] >= '!' && password[0] <= '~';

    if (lowercase) strength++;
    if (uppercase) strength++;
    if (number) strength++;
    if (symbol) strength++;

    switch (strength)
    {
        case 0:
            printf("Password too weak!\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is medium.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
    }
}

int main()
{
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}