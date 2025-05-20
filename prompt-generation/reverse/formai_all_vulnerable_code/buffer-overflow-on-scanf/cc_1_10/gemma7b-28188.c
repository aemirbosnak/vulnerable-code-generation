//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_LENGTH 20

int main()
{
    char password[PASSWORD_LENGTH];
    int i, strength = 0, min_length = 10, max_repeat = 3;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length)
    {
        strength -= 10;
        printf("Error: Password too short.\n");
    }

    // Check for character repetition
    for (i = 0; i < strlen(password); i++)
    {
        int count = 0;
        for (int j = 0; j < strlen(password); j++)
        {
            if (password[i] == password[j])
            {
                count++;
            }
        }
        if (count > max_repeat)
        {
            strength -= 5;
            printf("Error: Password has too much repetition.\n");
        }
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength -= 5;
        printf("Error: Password lacks uppercase letter.\n");
    }

    // Check for number
    if (!strchr(password, '0'))
    {
        strength -= 5;
        printf("Error: Password lacks number.\n");
    }

    // Calculate password strength
    strength += (strlen(password) * 3) / PASSWORD_LENGTH;

    // Display password strength
    printf("Password strength: %d/%d\n", strength, PASSWORD_LENGTH);

    return 0;
}