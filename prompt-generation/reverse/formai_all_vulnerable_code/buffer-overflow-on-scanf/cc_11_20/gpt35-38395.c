//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*                          PASSWORD STRENGTH CHECKER                            */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Password strength indicators
#define STR_NONE 0
#define STR_WEAK 1
#define STR_MEDIUM 2
#define STR_STRONG 3

// Password strength checker function
int passwordStrengthChecker(char password[])
{
    int length = strlen(password), 
        hasDigit = 0,
        hasUppercase = 0, 
        hasLowercase = 0,
        hasPunctuation = 0,
        strength = STR_NONE;

    // Check length
    if (length >= 8)
    {
        strength = STR_WEAK;

        // Check for digits, uppercase, lowercase, and punctuation
        for (int i = 0; i < length; i++)
        {
            if (isdigit(password[i]))
            {
                hasDigit = 1;
            }
            else if (isupper(password[i]))
            {
                hasUppercase = 1;
            }
            else if (islower(password[i]))
            {
                hasLowercase = 1;
            }
            else if (ispunct(password[i]))
            {
                hasPunctuation = 1;
            }

            // Check strength level based on password criteria
            if (hasDigit && hasUppercase && hasLowercase && hasPunctuation)
            {
                strength = STR_STRONG;
                break;
            }
            else if ((hasDigit && hasUppercase && hasLowercase) || 
                     (hasDigit && hasUppercase && hasPunctuation) || 
                     (hasDigit && hasLowercase && hasPunctuation) || 
                     (hasUppercase && hasLowercase && hasPunctuation))
            {
                strength = STR_MEDIUM;
            }
        }
    }

    return strength;
}

int main()
{
    char password[50];
    int strength;

    // Getting the password from user input
    printf("Greetings Sir/Madam Sherlock Holmes! May I know a good password that you want to check the strength of?\n");
    printf("Kindly enter the password: ");
    scanf("%s", password);

    // Check password strength
    strength = passwordStrengthChecker(password);

    // Output strength result
    printf("\n");
    if (strength == STR_NONE)
    {
        printf("I'm sorry Sir/Madam, as per my analysis, the password does not meet the length requirement which is at least 8 characters long.\n");
    }
    else if (strength == STR_WEAK)
    {
        printf("I'm sorry Sir/Madam, as per my analysis, the password is weak and does not meet the required criteria of having at least one uppercase, one lowercase, one digit, and one punctuation.\n");
    }
    else if (strength == STR_MEDIUM)
    {
        printf("Well Done Sir/Madam, as per my analysis, the password is medium strength and meets some, but not all, of the criteria required which are having at least one uppercase, one lowercase, one digit, and one punctuation.\n");
    }
    else if (strength == STR_STRONG)
    {
        printf("Bravissimo Sir/Madam! As per my analysis, the password is strong and meets all criteria required, which are having at least one uppercase, one lowercase, one digit, and one punctuation.\n");
    }

    return 0;
}