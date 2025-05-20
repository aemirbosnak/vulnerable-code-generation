//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWD_LEN 256

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int strength = 0;
    int i;

    printf("Enter a password: ");
    scanf("%s", passwd);

    // Check password length
    if (strlen(passwd) < 8)
    {
        strength++;
    }

    // Check for upper case letter
    for (i = 0; i < strlen(passwd); i++)
    {
        if (isupper(passwd[i]))
        {
            strength++;
        }
    }

    // Check for lower case letter
    for (i = 0; i < strlen(passwd); i++)
    {
        if (islower(passwd[i]))
        {
            strength++;
        }
    }

    // Check for number
    for (i = 0; i < strlen(passwd); i++)
    {
        if (isdigit(passwd[i]))
        {
            strength++;
        }
    }

    // Check for special character
    for (i = 0; i < strlen(passwd); i++)
    {
        if (!isalnum(passwd[i]))
        {
            strength++;
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
            printf("Password strength: Strong\n");
            break;
        case 3:
            printf("Password strength: Very Strong\n");
            break;
    }

    return 0;
}