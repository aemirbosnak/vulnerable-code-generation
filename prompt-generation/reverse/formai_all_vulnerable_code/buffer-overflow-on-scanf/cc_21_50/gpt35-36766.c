//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[50]; // Declare a char array to hold the password
    int length, uppercase, lowercase, digits, special; // Declare integer variables to hold the various properties of the password
    int strength = 0; // Declare an integer variable to hold the password strength

    printf("My love, please enter your password: "); // Romantic message to prompt the user to enter their password
    scanf("%s", &password); // Store the password inputted by the user in the char array declared earlier

    length = strlen(password); // Retrieve the length of the password and store in variable 'length'

    // Loop through each character in the password and check if it satisfies the conditions of the password strength checker
    for(int i = 0; i < length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase = 1;
        }
        else if(password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase = 1;
        }
        else if(password[i] >= '0' && password[i] <= '9')
        {
            digits = 1;
        }
        else
        {
            special = 1;
        }
    }

    // Check if the password meets the criteria for a strong password
    if(length >= 8 && uppercase == 1 && lowercase == 1 && digits == 1 && special == 1)
    {
        strength = 4; // Password is considered 'Very Strong'
    }
    else if(length >= 6 && uppercase == 1 && lowercase == 1 && digits == 1)
    {
        strength = 3; // Password is considered 'Strong'
    }
    else if(length >= 4 && lowercase == 1 && digits == 1)
    {
        strength = 2; // Password is considered 'Fair'
    }
    else
    {
        strength = 1; // Password is considered 'Weak'
    }

    // Romantic message to display the strength of the password
    if(strength == 4)
    {
        printf("My sweet love, your password is very strong! I'm impressed!\n");
    }
    else if(strength == 3)
    {
        printf("My heart, your password is strong, but could be stronger. Keep it up!\n");
    }
    else if(strength == 2)
    {
        printf("My darling, your password is fair, but I know you can do better!\n");
    }
    else
    {
        printf("My dear, your password is weak. Please consider changing it for your safety!\n");
    }

    return 0;
}