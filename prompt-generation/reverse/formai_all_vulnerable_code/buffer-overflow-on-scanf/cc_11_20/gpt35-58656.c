//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This program performs password strength checking 
 * on a given password. Passwords must meet the following
 * criteria to be considered strong:
 *  - At least 8 characters long
 *  - Contains at least one uppercase letter
 *  - Contains at least one lowercase letter
 *  - Contains at least one special character ( @, #, $)
 *  - Contains at least one digit
 */


int main()
{
    //variables to hold password criteria
    int has_upper = 0;
    int has_lower = 0;
    int has_special = 0;
    int has_digit = 0;

    char password[50];
    int password_length;

    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    password_length = strlen(password);

    //loop through each character in password
    for(int i = 0; i < password_length; i++)
    {
        //check for uppercase letter
        if(isupper(password[i]))
        {
            has_upper = 1;
        }
        //check for lowercase letter
        if(islower(password[i]))
        {
            has_lower = 1;
        }
        //check for special character
        if(password[i] == '@' || password[i] == '#' || password[i] == '$')
        {
            has_special = 1;
        }
        //check for digit
        if(isdigit(password[i]))
        {
            has_digit = 1;
        }
    }

    //if password meets all criteria, it is strong
    if(password_length >= 8 && has_upper && has_lower && has_special && has_digit)
    {
        printf("Password is strong!\n");
    }
    else
    {
        printf("Password is not strong.\n");
        printf("Make sure it meets the following criteria:\n");
        printf("- At least 8 characters long\n");
        printf("- Contains at least one uppercase letter\n");
        printf("- Contains at least one lowercase letter\n");
        printf("- Contains at least one special character ( @, #, $)\n");
        printf("- Contains at least one digit\n");
    }

    return 0;
}