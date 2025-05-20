//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_PASS_LEN 255

int main()
{
    char password[MAX_PASS_LEN];
    int i, strength = 0, min_length = 8, upper_case_found = 0, number_found = 0;

    printf("Enter password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length)
    {
        printf("Password too short.\n");
        return 1;
    }

    // Check for upper case letter
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper_case_found = 1;
        }
    }

    // Check for number
    for (i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            number_found = 1;
        }
    }

    // Calculate password strength
    if (upper_case_found && number_found)
    {
        strength = 3;
    }
    else if (upper_case_found || number_found)
    {
        strength = 2;
    }
    else
    {
        strength = 1;
    }

    // Display password strength
    switch (strength)
    {
        case 3:
            printf("Password strength: Strong\n");
            break;
        case 2:
            printf("Password strength: Moderate\n");
            break;
        case 1:
            printf("Password strength: Weak\n");
            break;
    }

    return 0;
}