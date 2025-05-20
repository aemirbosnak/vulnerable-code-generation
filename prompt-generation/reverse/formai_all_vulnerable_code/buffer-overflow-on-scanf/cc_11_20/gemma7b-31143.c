//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char password[20];
    int i, strength = 0, min_length = 8;

    printf("Well, Watson, what is the password you wish to protect? ");
    scanf("%s", password);

    // Examine the password's length
    if (strlen(password) >= min_length)
    {
        strength++;
    }

    // Check for uppercase letters
    for (i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            strength++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            strength++;
        }
    }

    // Check for numbers
    for (i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            strength++;
        }
    }

    // Check for special characters
    for (i = 0; i < strlen(password); i++)
    {
        if (ispunct(password[i]))
        {
            strength++;
        }
    }

    // Calculate the password's strength
    switch (strength)
    {
        case 0:
            printf("Your password is as weak as a spider's thread, Watson.\n");
            break;
        case 1:
            printf("Your password is slightly better than a bar of soap, but could be improved.\n");
            break;
        case 2:
            printf("Your password is as strong as a vault door, but could be even stronger.\n");
            break;
        case 3:
            printf("Your password is as impenetrable as a fortress, Watson. Well done!\n");
            break;
    }

    return 0;
}