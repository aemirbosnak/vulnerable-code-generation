//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char password[100];
    int length, i, j, num, upper, lower, special;
    char message[200];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the length of the password
    length = strlen(password);

    // Initialize variables for checking password strength
    num = upper = lower = special = 0;

    // Loop through the password
    for(i = 0; i < length; i++)
    {
        // Check if the character is a number
        if(isdigit(password[i]))
        {
            num++;
        }
        // Check if the character is an uppercase letter
        else if(isupper(password[i]))
        {
            upper++;
        }
        // Check if the character is a lowercase letter
        else if(islower(password[i]))
        {
            lower++;
        }
        // Check if the character is a special character
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?')
        {
            special++;
        }
    }

    // Check if the password meets the strength requirements
    if(length >= 8 && num >= 1 && upper >= 1 && lower >= 1 && special >= 1)
    {
        printf("Your password is strong!\n");
    }
    else
    {
        printf("Your password is weak.\n");
    }

    // Give the user tips on how to make their password stronger
    if(length < 8)
    {
        strcat(message, "Your password is too short. ");
    }
    if(num < 1)
    {
        strcat(message, "Your password should contain at least one number. ");
    }
    if(upper < 1)
    {
        strcat(message, "Your password should contain at least one uppercase letter. ");
    }
    if(lower < 1)
    {
        strcat(message, "Your password should contain at least one lowercase letter. ");
    }
    if(special < 1)
    {
        strcat(message, "Your password should contain at least one special character. ");
    }
    printf("Tips: %s\n", message);

    return 0;
}