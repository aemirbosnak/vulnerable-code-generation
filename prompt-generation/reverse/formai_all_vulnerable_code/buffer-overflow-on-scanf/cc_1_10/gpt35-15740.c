//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the password is strong enough
bool isPasswordStrong(char password[])
{
    int length = strlen(password);

    // Password should be at least 8 characters long
    if(length < 8)
        return false;

    bool hasUpperCase = false, hasLowerCase = false, hasDigit = false;

    // Check if password has at least one uppercase, one lowercase and one digit character
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            hasUpperCase = true;
        else if(password[i] >= 'a' && password[i] <= 'z')
            hasLowerCase = true;
        else if(password[i] >= '0' && password[i] <= '9')
            hasDigit = true;

        // If password has all required characters, return true
        if(hasUpperCase && hasLowerCase && hasDigit)
            return true;
    }

    // If password doesn't have all required characters, return false
    return false;
}

// Function to print appropriate message based on password strength
void printPasswordStrength(char password[])
{
    if(isPasswordStrong(password))
        printf("Congratulations! Your password is strong.\n");
    else
        printf("Your password is weak. Please make it stronger.\n");
}

// Main function to take input and test password strength
int main()
{
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    printPasswordStrength(password);

    return 0;
}