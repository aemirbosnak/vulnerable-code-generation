//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, digits = 0, uppercase = 0, lowercase = 0, specialChar = 0;

    printf("Please enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Loop through each character in the password
    for(int i = 0; i < length; i++) 
    {
        if(isdigit(password[i])) 
        {
            digits++; // Count the digits in the password
        }
        else if(isupper(password[i]))
        {
            uppercase++; // Count the uppercase letters in the password
        }
        else if(islower(password[i]))
        {
            lowercase++; // Count the lowercase letters in the password
        }
        else if(!isdigit(password[i]) && !isalpha(password[i]))
        {
            specialChar++; // Count the special characters in the password
        }
    }

    // Check if the password meets the minimum requirements
    if(length < 8 || digits < 2 || uppercase < 1 || lowercase < 1 || specialChar < 1) 
    {
        printf("Your password is weak! Your password must meet the following requirements:\n");
        printf("- At least 8 characters in length\n");
        printf("- At least 2 digits\n");
        printf("- At least 1 uppercase letter\n");
        printf("- At least 1 lowercase letter\n");
        printf("- At least 1 special character\n");
    } 
    else 
    {
        printf("Congratulations! Your password is strong!");
    }

    return 0;
}