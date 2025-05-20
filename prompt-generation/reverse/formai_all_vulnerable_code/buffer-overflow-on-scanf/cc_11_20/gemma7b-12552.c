//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWD_LEN 128

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int i, strength = 0, min_length = 8, max_length = 16;

    printf("Enter your password: ");
    scanf("%s", passwd);

    // Check password length
    if (strlen(passwd) < min_length)
    {
        printf("Error: Password too short. Minimum %d characters required.\n", min_length);
    }
    else if (strlen(passwd) > max_length)
    {
        printf("Error: Password too long. Maximum %d characters allowed.\n", max_length);
    }

    // Check for uppercase letter
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= 'A' && passwd[i] <= 'Z')
        {
            strength++;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= 'a' && passwd[i] <= 'z')
        {
            strength++;
        }
    }

    // Check for number
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= '0' && passwd[i] <= '9')
        {
            strength++;
        }
    }

    // Check for special character
    for (i = 0; i < strlen(passwd); i++)
    {
        if (passwd[i] >= '!' && passwd[i] <= '~')
        {
            strength++;
        }
    }

    // Calculate password strength
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
            printf("Error: Invalid password strength.\n");
            break;
    }

    return 0;
}