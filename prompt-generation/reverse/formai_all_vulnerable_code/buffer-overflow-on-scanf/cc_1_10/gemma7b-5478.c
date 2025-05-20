//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;
    int strength = 0;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password length
    password_length = strlen(password);

    // Calculate the password strength
    if (password_length >= 8)
    {
        strength++;
    }
    if (hasUppercase(password))
    {
        strength++;
    }
    if (hasNumber(password))
    {
        strength++;
    }

    // Display the password strength
    switch (strength)
    {
        case 0:
            printf("Your password is weak.\n");
            break;
        case 1:
            printf("Your password is moderate.\n");
            break;
        case 2:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}

int hasUppercase(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            return 1;
        }
    }

    return 0;
}

int hasNumber(char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            return 1;
        }
    }

    return 0;
}