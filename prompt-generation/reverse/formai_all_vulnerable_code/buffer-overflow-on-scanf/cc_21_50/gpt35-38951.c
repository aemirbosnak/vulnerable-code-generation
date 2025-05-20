//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* This program checks the password strength */

int main()
{
    char password[50];
    int length, contains_uppercase, contains_lowercase, contains_digit, contains_special_char;
    int strength = 0;

    printf("Hi there! Let's check your password strength.\n");
    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        /* Checking if the password contains uppercase letters */
        if (isupper(password[i]))
        {
            strength += 3;
            contains_uppercase = 1;
        }

        /* Checking if the password contains lowercase letters */
        if (islower(password[i]))
        {
            strength += 3;
            contains_lowercase = 1;
        }

        /* Checking if the password contains digits */
        if (isdigit(password[i]))
        {
            strength += 2;
            contains_digit = 1;
        }

        /* Checking if the password contains special characters */
        if (!isalnum(password[i]))
        {
            strength += 5;
            contains_special_char = 1;
        }
    }
    
    /* Checking password length */
    if (length >= 8 && length <= 12)
    {
        strength += 4;
    }
    else if (length > 12)
    {
        strength += 6;
    }
    else
    {
        printf("Your password is too short!\n");
        return 0;
    }

    /* Giving feedback based on password strength */
    printf("Your password strength is: %d\n", strength);
    if (contains_uppercase && contains_lowercase && contains_digit && contains_special_char)
    {
        printf("Wow! Your password is very strong!\n");
    }
    else if ((contains_uppercase && contains_lowercase && contains_digit) || 
             (contains_uppercase && contains_lowercase && contains_special_char) ||
             (contains_uppercase && contains_digit && contains_special_char) ||
             (contains_lowercase && contains_digit && contains_special_char))
    {
        printf("Your password is strong, but could be better!\n");
    }
    else
    {
        printf("Your password is weak, please make it stronger!\n");
    }

    return 0;
}