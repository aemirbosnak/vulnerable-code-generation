//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8

int main()
{
    char password[256];
    int i, strength = 0, min_strength = 0, flag = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    for (i = 0; password[i] != '\0'; i++)
    {
        // Check for uppercase letter
        if (isupper(password[i]))
            strength++;

        // Check for lowercase letter
        if (islower(password[i]))
            strength++;

        // Check for number
        if (isdigit(password[i]))
            strength++;

        // Check for special character
        if (ispunct(password[i]))
            strength++;
    }

    min_strength = strength / 4;

    if (strength < MIN_PASSWORD_LENGTH)
    {
        flag = 1;
        printf("Weak password. Please use at least %d characters.", MIN_PASSWORD_LENGTH);
    }
    else if (min_strength < 1)
    {
        flag = 1;
        printf("Password strength: Poor. Please use more uppercase, lowercase or numbers.");
    }
    else if (min_strength < 2)
    {
        flag = 1;
        printf("Password strength: Fair. Please use more uppercase, lowercase or numbers.");
    }
    else if (min_strength < 3)
    {
        flag = 1;
        printf("Password strength: Good. Please use more uppercase, lowercase or numbers.");
    }
    else
    {
        flag = 1;
        printf("Password strength: Strong. You have a strong password.");
    }

    if (flag)
    {
        printf("\nPlease try again with a stronger password.");
    }

    return 0;
}