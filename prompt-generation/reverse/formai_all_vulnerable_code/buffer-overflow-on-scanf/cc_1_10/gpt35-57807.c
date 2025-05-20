//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
    This program checks the strength of a password based on various rules such as length, presence of lower and upper case alphabets,
    numbers and special characters.
*/

bool isUpperCase(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLowerCase(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isNumber(char c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSpecialChar(char c)
{
    if(!isUpperCase(c) && !isLowerCase(c) && !isNumber(c))
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
    char password[100];
    int length, score = 0, upperCount = 0, lowerCount = 0, numberCount = 0, specialCount = 0;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);

    // Checking length
    if(length >= 8 && length <= 16)
    {
        score++;
    }

    // Counting the number of uppercase, lowercase, numbers and special characters
    for(int i=0; i<length; i++)
    {
        if(isUpperCase(password[i]))
        {
            upperCount++;
        }
        else if(isLowerCase(password[i]))
        {
            lowerCount++;
        }
        else if(isNumber(password[i]))
        {
            numberCount++;
        }
        else if(isSpecialChar(password[i]))
        {
            specialCount++;
        }
    }

    // Checking if all types of characters are present
    if(upperCount > 0 && lowerCount > 0 && numberCount > 0 && specialCount > 0)
    {
        score++;
    }

    // Additional points for having all types of characters in a sequential order
    for(int i=0; i<length-3; i++)
    {
        if(isUpperCase(password[i]) && isLowerCase(password[i+1]) && isNumber(password[i+2]) && isSpecialChar(password[i+3]))
        {
            score++;
        }
    }

    printf("\nPassword Strength Score: %d\n", score);

    if(score < 2)
    {
        printf("Password is weak!");
    }
    else if(score < 4)
    {
        printf("Password is moderate.");
    }
    else
    {
        printf("Password is strong!");
    }

    return 0;
}