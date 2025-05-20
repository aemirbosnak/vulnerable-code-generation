//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// function to check if a password is strong enough
bool checkPasswordStrength(char* password)
{
    // length of password
    int n = strlen(password);
    
    // count of uppercase, lowercase, digits, special characters
    int upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;
    
    // loop through each character in the password
    for (int i = 0; i < n; i++)
    {
        char ch = password[i];
        
        // check if the character is uppercase
        if (isupper(ch))
            upperCount++;
        // check if the character is lowercase
        else if (islower(ch))
            lowerCount++;
        // check if the character is a digit
        else if (isdigit(ch))
            digitCount++;
        // check if the character is a special character
        else
            specialCount++;
    }
    
    // calculate the password strength score
    int score = 0;
    
    // add points to the score based on the number of uppercase, lowercase, digits, and special characters
    score += (upperCount > 0) ? 10 : 0;
    score += (lowerCount > 0) ? 10 : 0;
    score += (digitCount > 0) ? 10 : 0;
    score += (specialCount > 0) ? 20 : 0;
    
    // add points to the score based on the length of the password
    if (n >= 8 && n <= 12)
        score += 10;
    else if (n > 12)
        score += 20;
    
    // check if the password meets the minimum strength score requirement
    if (score >= 60)
        return true;
    else
        return false;
}

int main()
{
    char password[50];
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    if (checkPasswordStrength(password))
        printf("Your password is strong enough.\n");
    else
        printf("Your password is not strong enough.\n");
    
    return 0;
}