//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 100

int main()
{
    char password[MAX_LENGTH];
    int length, upperCase, lowerCase, numeric, specialChar;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    upperCase = 0;
    lowerCase = 0;
    numeric = 0;
    specialChar = 0;

    // Check for uppercase letters
    for(int i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            upperCase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for(int i=0; i<length; i++)
    {
        if(islower(password[i]))
        {
            lowerCase = 1;
            break;
        }
    }

    // Check for numeric characters
    for(int i=0; i<length; i++)
    {
        if(isdigit(password[i]))
        {
            numeric = 1;
            break;
        }
    }

    // Check for special characters
    for(int i=0; i<length; i++)
    {
        if(!isalnum(password[i]))
        {
            specialChar = 1;
            break;
        }
    }

    // Check password strength
    if(length < 8)
    {
        printf("Password is too weak.\n");
    }
    else if(length >= 8 && (upperCase || lowerCase || numeric || specialChar))
    {
        printf("Password is strong.\n");
    }
    else if(length >= 8 &&!(upperCase || lowerCase || numeric || specialChar))
    {
        printf("Password is medium.\n");
    }
    else
    {
        printf("Password is weak.\n");
    }

    return 0;
}