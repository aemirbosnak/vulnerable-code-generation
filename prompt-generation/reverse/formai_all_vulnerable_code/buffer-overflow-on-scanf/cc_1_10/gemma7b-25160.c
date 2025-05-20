//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASS_LENGTH 256

char password_strength(char *pass)
{
    int pass_length = strlen(pass);
    char strength = 'F';

    // Check for minimum length
    if (pass_length < 8)
    {
        strength = 'W';
    }

    // Check for uppercase letter
    if (!strchr(pass, 'A'))
    {
        strength = 'S';
    }

    // Check for lowercase letter
    if (!strchr(pass, 'a'))
    {
        strength = 'S';
    }

    // Check for number
    if (!strchr(pass, '0') || !strchr(pass, '9'))
    {
        strength = 'S';
    }

    // Check for special character
    if (!strchr(pass, '$') && !strchr(pass, '#') && !strchr(pass, '%') && !strchr(pass, '&'))
    {
        strength = 'S';
    }

    return strength;
}

int main()
{
    char pass[MAX_PASS_LENGTH];

    printf("Enter your password: ");
    scanf("%s", pass);

    char strength = password_strength(pass);

    switch (strength)
    {
        case 'F':
            printf("Your password is strong.\n");
            break;
        case 'S':
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 'W':
            printf("Your password is very weak. Please use a stronger password.\n");
            break;
    }

    return 0;
}