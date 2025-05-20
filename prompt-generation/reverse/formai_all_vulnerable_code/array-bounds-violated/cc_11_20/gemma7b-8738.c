//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8, max_repeat = 3;

    printf("Enter a futuristic password: ");
    scanf("%s", password);

    // Calculate password strength
    for (i = 0; password[i] != '\0'; i++)
    {
        // Points to lowercase letter
        if (password[i] >= 'a' && password[i] <= 'z')
            strength++;

        // Points to uppercase letter
        else if (password[i] >= 'A' && password[i] <= 'Z')
            strength++;

        // Points to number
        else if (password[i] >= '0' && password[i] <= '9')
            strength++;

        // Points to special character
        else if (password[i] >= '!' && password[i] <= '~')
            strength++;

        // Repeat character check
        if (password[i] == password[i-1] && i > 0)
            strength--;
    }

    // Check password length
    if (strlen(password) < min_length)
        strength--;

    // Print password strength
    switch (strength)
    {
        case 5:
            printf("Your password is super strong!\n");
            break;
        case 4:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is acceptable.\n");
            break;
        case 2:
            printf("Your password is weak.\n");
            break;
        case 1:
            printf("Your password is very weak.\n");
            break;
        default:
            printf("Error.\n");
    }

    return 0;
}