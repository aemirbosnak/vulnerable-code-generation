//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < 8)
    {
        strength += 1;
    }

    // Check for uppercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            strength += 2;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            strength += 2;
        }
    }

    // Check for numbers
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            strength += 2;
        }
    }

    // Check for special characters
    for (int i = 0; i < strlen(password); i++)
    {
        if (ispunct(password[i]))
        {
            strength += 2;
        }
    }

    // Print password strength
    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        default:
            printf("Password strength: Unknown\n");
            break;
    }

    return 0;
}