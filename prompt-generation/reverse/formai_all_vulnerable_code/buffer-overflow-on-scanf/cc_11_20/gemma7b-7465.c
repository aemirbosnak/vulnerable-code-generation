//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, min_length = 8;
    printf("Enter your password: ");
    scanf("%s", password);

    // Checking password length
    if (strlen(password) < min_length)
    {
        printf("Error: Your password is too short. Please try again.\n");
        return 1;
    }

    // Checking for uppercase letters
    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            strength++;
    }

    // Checking for lowercase letters
    for (i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
            strength++;
    }

    // Checking for numbers
    for (i = 0; password[i] != '\0'; i++)
    {
        if (isdigit(password[i]))
            strength++;
    }

    // Checking for symbols
    for (i = 0; password[i] != '\0'; i++)
    {
        if (ispunct(password[i]))
            strength++;
    }

    // Calculating password strength
    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please try again.\n");
            break;
        case 1:
            printf("Your password is weak. Please try again.\n");
            break;
        case 2:
            printf("Your password is moderate. It's okay.\n");
            break;
        case 3:
            printf("Your password is strong. Good job!\n");
            break;
        case 4:
            printf("Your password is very strong. You're a master of security!\n");
            break;
    }

    return 0;
}