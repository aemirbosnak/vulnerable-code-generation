//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50]; 
    int length, i, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) // Check password length
    {
        printf("Password length should be minimum 8 characters.");
        return 0;
    }
    else
    {
        for (i = 0; i < length; i++) // Check each character of password
        {
            if (isupper(password[i]))
            {
                upper = 1; // Uppercase character found
            }
            else if (islower(password[i]))
            {
                lower = 1; // Lowercase character found
            }
            else if (isdigit(password[i]))
            {
                digit = 1; // Digit character found
            }
            else if (password[i] == '@' || password[i] == '#' || password[i] == '$')
            {
                special = 1; // Special character found
            }
        }

        if (upper && lower && digit && special) // Check if all conditions are satisfied
        {
            printf("Strong password!\n");
        }
        else
        {
            printf("Weak password. Must contain at least one uppercase character, one lowercase character, one digit, and one special character '@', '#' or '$'\n");
        }
    }

    return 0;
}