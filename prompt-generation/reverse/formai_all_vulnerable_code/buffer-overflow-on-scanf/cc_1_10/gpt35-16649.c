//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Function to check the strength of a password */
bool isStrongPassword(char* password)
{
    int uppercase = 0; // Count of uppercase letters
    int lowercase = 0; // Count of lowercase letters
    int digits = 0; // Count of digits
    int specials = 0; // Count of special characters
    int length = strlen(password); // Length of the password
    
    // Loop through each character of the password string
    for(int i=0; i<length; i++)
    {
        char ch = password[i]; // Get the current character
        
        // Check if the character is an uppercase letter
        if(ch >= 'A' && ch <= 'Z')
        {
            uppercase++;
        }
        // Check if the character is a lowercase letter
        else if(ch >= 'a' && ch <= 'z')
        {
            lowercase++;
        }
        // Check if the character is a digit
        else if(ch >= '0' && ch <= '9')
        {
            digits++;
        }
        // Check if the character is a special character
        else
        {
            specials++;
        }
    }
    
    // Check if the password meets the minimum requirements
    if(length >= 8 && uppercase >= 1 && lowercase >= 1 && digits >= 1 && specials >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char password[50]; // Variable to store the password
    
    printf("Please enter your password: ");
    scanf("%s", password); // Get the password from the user
    
    if(isStrongPassword(password))
    {
        printf("Congratulations! Your password is strong.\n");
    }
    else
    {
        printf("Sorry, your password is not strong enough. Please make sure it is at least 8 characters long and contains uppercase letters, lowercase letters, digits, and special characters.\n");
    }
    
    return 0;
}