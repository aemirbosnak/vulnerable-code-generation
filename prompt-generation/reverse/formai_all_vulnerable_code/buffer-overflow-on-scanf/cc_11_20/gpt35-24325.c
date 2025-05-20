//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include <stdio.h>
#include <string.h>

// Function to check if the password meets the minimum requirements.
int is_password_strong(char password[])
{
    int length = strlen(password);
    int uppercase_flag = 0, lowercase_flag = 0, digit_flag = 0, special_char_flag = 0;

    // Checking for uppercase letters
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z') 
        {
            uppercase_flag = 1;
            break;
        }
    }

    // Checking for lowercase letters
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z') 
        {
            lowercase_flag = 1;
            break;
        }
    }

    // Checking for digits
    for(int i=0; i<length; i++)
    {
        if(password[i] >= '0' && password[i] <= '9') 
        {
            digit_flag = 1;
            break;
        }
    }

    // Checking for special characters
    for(int i=0; i<length; i++)
    {
        if(!(password[i] >= '0' && password[i] <= '9') &&
           !(password[i] >= 'A' && password[i] <= 'Z') &&
           !(password[i] >= 'a' && password[i] <= 'z')) 
        {
            special_char_flag = 1;
            break;
        }
    }

    // Check if all the conditions are met and return the status
    if(uppercase_flag && lowercase_flag && digit_flag && special_char_flag && length >= 8)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char password[100];
    printf("Enter password to check its strength: ");
    scanf("%s", password);

    if(is_password_strong(password))
    {
        printf("Password is strong!\n");
    }
    else
    {
        printf("Password is weak! Please make sure it contains at least 8 characters, including uppercase and lowercase letters, digits and special characters.\n");
    }

    return 0;
}