//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[255];
    int i, strength = 0, hasLower = 0, hasUpper = 0, hasNumber = 0, hasSymbol = 0;

    printf("Enter a password: ");
    gets(password);

    for (i = 0; password[i] != '\0'; i++)
    {
        // Check for lowercase letter
        if (islower(password[i]))
            hasLower = 1;

        // Check for uppercase letter
        if (isupper(password[i]))
            hasUpper = 1;

        // Check for number
        if (isdigit(password[i]))
            hasNumber = 1;

        // Check for symbol
        if (ispunct(password[i]))
            hasSymbol = 1;
    }

    // Calculate password strength
    if (hasLower && hasUpper && hasNumber && hasSymbol)
        strength = 5;
    else if (hasLower || hasUpper || hasNumber || hasSymbol)
        strength = 3;
    else
        strength = 1;

    // Display password strength
    switch (strength)
    {
        case 5:
            printf("Password strength: Very strong\n");
            break;
        case 3:
            printf("Password strength: Moderate\n");
            break;
        case 1:
            printf("Password strength: Weak\n");
            break;
    }

    return 0;
}