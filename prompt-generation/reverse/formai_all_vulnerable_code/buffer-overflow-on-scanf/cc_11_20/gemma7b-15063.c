//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = 1;
    }

    // Check for uppercase letter
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            strength = 2;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            strength = 3;
        }
    }

    // Check for number
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            strength = 4;
        }
    }

    // Check for special character
    for (int i = 0; i < strlen(password); i++)
    {
        if (!isalnum(password[i]))
        {
            strength = 5;
        }
    }

    // Print strength
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
        case 4:
            printf("Password strength: Very Strong\n");
            break;
        case 5:
            printf("Password strength: Excellent\n");
            break;
    }

    return 0;
}