//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < 8)
    {
        printf("Error: Password is too short.\n");
    }
    else if (password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Error: Password is too long.\n");
    }
    else
    {
        int strength = 0;
        for (int i = 0; i < password_length; i++)
        {
            if (isupper(password[i]))
            {
                strength++;
            }
            if (islower(password[i]))
            {
                strength++;
            }
            if (isdigit(password[i]))
            {
                strength++;
            }
            if (ispunct(password[i]))
            {
                strength++;
            }
        }

        if (strength < 3)
        {
            printf("Error: Password is too weak.\n");
        }
        else
        {
            printf("Password is strong.\n");
        }
    }

    return 0;
}