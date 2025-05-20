//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Basic function to check if a character is a digit or not
int is_digit(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

// Basic function to check if a character is a lowercase alphabet or not
int is_lower(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}

// Basic function to check if a character is an uppercase alphabet or not
int is_upper(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return 1;
    return 0;
}

// Basic function to check if a character is a special character or not
int is_special(char ch)
{
    if(!is_digit(ch) && !is_lower(ch) && !is_upper(ch))
        return 1;
    return 0;
}

// Function to calculate the password strength
int check_strength(char* password)
{
    int len = strlen(password);
    int strength = 0;
    int i;

    // Checking password length
    if(len >= 8)
        strength++;

    // Checking for presence of digits, lower and upper case letters and special characters
    for(i=0;i<len;i++)
    {
        char ch = password[i];
        if(is_digit(ch))
        {
            strength++;
            break;
        }
    }

    for(i=0;i<len;i++)
    {
        char ch = password[i];
        if(is_lower(ch))
        {
            strength++;
            break;
        }
    }

    for(i=0;i<len;i++)
    {
        char ch = password[i];
        if(is_upper(ch))
        {
            strength++;
            break;
        }
    }

    for(i=0;i<len;i++)
    {
        char ch = password[i];
        if(is_special(ch))
        {
            strength++;
            break;
        }
    }

    return strength;
}

int main()
{
    char password[100];
    int strength;

    printf("Welcome to our Password Strength Checker Shape Shifting Program!\n");
    printf("Please enter a password to check its strength:\n");

    scanf("%s", password);

    strength = check_strength(password);

    if(strength == 0 || strength == 1)
        printf("Your password strength is weak.\n");
    else if(strength == 2)
        printf("Your password strength is medium.\n");
    else if(strength == 3 || strength == 4)
        printf("Your password strength is strong.\n");
    else
        printf("Something went wrong, please try again.\n");

    return 0;
}