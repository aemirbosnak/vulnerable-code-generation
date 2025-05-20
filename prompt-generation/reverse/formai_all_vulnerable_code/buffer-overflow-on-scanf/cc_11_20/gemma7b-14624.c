//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWD_LEN 255

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", passwd);

    // Check for minimum length
    if (strlen(passwd) < 8)
    {
        strength = -1;
        printf("Error: Password too short.\n");
    }

    // Check for uppercase letter
    if (strchr(passwd, toupper(rand() % 26)) != NULL)
    {
        strength++;
    }

    // Check for lowercase letter
    if (strchr(passwd, tolower(rand() % 26)) != NULL)
    {
        strength++;
    }

    // Check for number
    if (strchr(passwd, rand() % 10 + '0') != NULL)
    {
        strength++;
    }

    // Check for special character
    if (strchr(passwd, rand() % 32 + 32) != NULL)
    {
        strength++;
    }

    // Print strength
    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Fair\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        case -1:
            printf("Error: Invalid password.\n");
            break;
    }

    return 0;
}