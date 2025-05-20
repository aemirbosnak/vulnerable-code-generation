//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A function to check the password strength
void check_password_strength(char* password)
{
    int i, digits = 0, special_chars = 0, length = strlen(password), uppercase = 0, lowercase = 0;
    float strength_score = 0.0;

    // Checking the length of password
    if (length >= 8 && length <= 20) 
    {
        // Counting the number of digits, special characters, uppercase and lowercase letters
        for (i = 0; password[i] != '\0'; i++) 
        {
            if (isdigit(password[i])) 
            {
                digits++;
            } 
            else if (ispunct(password[i])) 
            {
                special_chars++;
            } 
            else if (isupper(password[i])) 
            {
                uppercase++;
            } 
            else if (islower(password[i])) 
            {
                lowercase++;
            }
        }

        // Calculating score based on the password criteria
        if (digits >= 2) 
        {
            strength_score += 0.3;
        }

        if (special_chars >= 1) 
        {
            strength_score += 0.3;
        }

        if (uppercase >= 1 && lowercase >= 1) 
        {
            strength_score += 0.4;
        }

        // Printing the password strength based on the strength score
        if (strength_score <= 0.5) 
        {
            printf("Password Strength: Weak\n");
        } 
        else if (strength_score > 0.5 && strength_score <= 0.7) 
        {
            printf("Password Strength: Medium\n");
        } 
        else if (strength_score > 0.7 && strength_score <= 1.0) 
        {
            printf("Password Strength: Strong\n");
        }

    } 
    else 
    {
        printf("Password Length should be between 8 and 20 characters.\n");
    }
}

int main()
{
    char password[20];
    printf("Enter Password: ");
    scanf("%s", password);

    check_password_strength(password);
    return 0;
}