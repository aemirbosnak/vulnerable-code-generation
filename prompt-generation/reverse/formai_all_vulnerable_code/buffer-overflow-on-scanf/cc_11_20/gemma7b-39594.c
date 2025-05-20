//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_LENGTH 16

int main()
{
    char password[PASSWORD_LENGTH];
    int i, strength = 0, valid = 0;

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the password length
    if (strlen(password) < PASSWORD_LENGTH)
    {
        printf("Error: password too short.\n");
        return 1;
    }

    // Iterate over the password characters
    for (i = 0; i < PASSWORD_LENGTH; i++)
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

    // Check if the password meets the minimum requirements
    if (strength >= 3)
        valid = 1;

    // Print the password strength
    printf("Password strength: ");
    switch (strength)
    {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Fair\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        default:
            printf("Very Strong\n");
            break;
    }

    // Check if the password is valid
    if (valid)
    {
        printf("Password valid.\n");
    }
    else
    {
        printf("Error: password invalid.\n");
    }

    return 0;
}