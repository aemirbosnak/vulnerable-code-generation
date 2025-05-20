//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    // Play the role of a secret agent
    printf("Greetings, Agent. You're on a mission to crack a password.\n");

    // Get the password from the user
    printf("Enter the password: ");
    scanf("%s", password);

    // Check the password strength
    int strength = check_password_strength(password);

    // Display the password strength
    switch (strength)
    {
        case 0:
            printf("The password is very weak. It is easy to guess.\n");
            break;
        case 1:
            printf("The password is weak. It can be easily cracked.\n");
            break;
        case 2:
            printf("The password is good. It is difficult to guess.\n");
            break;
        case 3:
            printf("The password is strong. It is very difficult to guess.\n");
            break;
        case 4:
            printf("The password is extremely strong. It is impossible to guess.\n");
            break;
    }

    // Continue the mission
    printf("Thank you for your help, Agent. You have cracked the password.\n");

    return 0;
}

int check_password_strength(char *password)
{
    int length = strlen(password);
    int has_numbers = 0;
    int has_letters = 0;
    int has_symbols = 0;

    // Check for numbers
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            has_numbers = 1;
        }
    }

    // Check for letters
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_letters = 1;
        }
    }

    // Check for symbols
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= '!' && password[i] <= '~')
        {
            has_symbols = 1;
        }
    }

    // Calculate the password strength
    int strength = 0;
    if (has_numbers)
    {
        strength++;
    }
    if (has_letters)
    {
        strength++;
    }
    if (has_symbols)
    {
        strength++;
    }
    return strength;
}