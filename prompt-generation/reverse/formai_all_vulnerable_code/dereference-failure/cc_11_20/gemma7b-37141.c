//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASS_LEN 255

typedef struct PasswordStrength
{
    int strength;
    char* password;
} PasswordStrength;

int main()
{
    PasswordStrength ps;
    ps.strength = 0;
    ps.password = NULL;

    char password[MAX_PASS_LEN];

    printf("Enter your password: ");
    fgets(password, MAX_PASS_LEN, stdin);

    ps.password = strdup(password);

    int min_chars = 0, num_digits = 0, has_special = 0;

    for (int i = 0; ps.password[i] != '\0'; i++)
    {
        if (islower(ps.password[i]))
            min_chars++;
        else if (isdigit(ps.password[i]))
            num_digits++;
        else if (ispunct(ps.password[i]))
            has_special++;
    }

    if (min_chars >= 8)
        ps.strength++;
    if (num_digits >= 2)
        ps.strength++;
    if (has_special)
        ps.strength++;

    switch (ps.strength)
    {
        case 0:
            printf("Your password is weak.\n");
            break;
        case 1:
            printf("Your password is somewhat weak.\n");
            break;
        case 2:
            printf("Your password is good.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
    }

    return 0;
}