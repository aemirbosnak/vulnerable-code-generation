//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[20];
    int strength = 0;
    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = -1;
    }
    // Check for uppercase letter
    else if (!isupper(password[0]))
    {
        strength = -2;
    }
    // Check for lowercase letter
    else if (!islower(password[0]))
    {
        strength = -3;
    }
    // Check for number
    else if (!isdigit(password[0]))
    {
        strength = -4;
    }
    // Check for special character
    else if (!ispunct(password[0]))
    {
        strength = -5;
    }
    // If all conditions are met, strength is 1
    else
    {
        strength = 1;
    }

    // Print strength
    switch (strength)
    {
        case -1:
            printf("Password too short!\n");
            break;
        case -2:
            printf("Password lacks uppercase letter!\n");
            break;
        case -3:
            printf("Password lacks lowercase letter!\n");
            break;
        case -4:
            printf("Password lacks number!\n");
            break;
        case -5:
            printf("Password lacks special character!\n");
            break;
        case 1:
            printf("Password is strong!\n");
            break;
    }

    return 0;
}