//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[256];
    int strength = 0;
    int i;

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
        if (!isalnum(password[i]))
            strength++;
    }

    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Strong\n");
            break;
        case 3:
            printf("Password strength: Excellent\n");
            break;
    }

    return 0;
}