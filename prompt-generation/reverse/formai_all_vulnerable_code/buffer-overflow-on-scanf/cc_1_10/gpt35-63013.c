//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

// Function to check whether the string is a valid integer
bool isNumber(char* password)
{
    int i = 0;

    // Check for negative integers
    if (password[0] == '-')
        i = 1;
    for (; password[i] != 0; i++)
    {
        // Check if each digit is a number
        if (!isdigit(password[i]))
            return false;
    }

    return true;
}

// Function to check password strength
void checkPassword(char* password)
{
    int passwordLength = strlen(password);

    // Password length must be 8 or greater
    if (passwordLength < 8)
    {
        printf("Password too short!\n");
        return;
    }

    // Password must contain at least one uppercase letter, one lowercase letter, and one number
    bool containsLowercase = false, containsUppercase = false, containsNumber = false;
    for (int i = 0; i < passwordLength; i++)
    {
        if (islower(password[i]))
            containsLowercase = true;
        else if (isupper(password[i]))
            containsUppercase = true;
        else if (isdigit(password[i]))
            containsNumber = true;

        if (containsLowercase && containsUppercase && containsNumber)
            break;
    }
    
    // Password does not meet requirements
    if (!containsLowercase || !containsUppercase || !containsNumber)
    {
        printf("Password does not meet requirements!\n");
        return;
    }

    // Password meets all requirements
    printf("Password strength is strong.\n");
}

int main()
{
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    checkPassword(password);

    return 0;
}