//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
int check_password_strength(char password[])
{
    int len = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    
    // Check if password contains uppercase letter, lowercase letter, digit and special character
    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = 1;
        }
        else if (islower(password[i]))
        {
            has_lower = 1;
        }
        else if (isdigit(password[i]))
        {
            has_digit = 1;
        }
        else if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~'))
        {
            has_special = 1;
        }
    }
    
    // Calculate password strength score
    int score = 0;
    if (len >= 8)
    {
        score += 1;
    }
    if (has_upper && has_lower)
    {
        score += 1;
    }
    if (has_digit)
    {
        score += 1;
    }
    if (has_special)
    {
        score += 1;
    }
    
    return score;
}

int main()
{
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);
    
    // Check password strength
    int score = check_password_strength(password);
    
    // Print password strength
    if (score == 0)
    {
        printf("Very weak password\n");
    }
    else if (score == 1)
    {
        printf("Weak password\n");
    }
    else if (score == 2)
    {
        printf("Moderate password\n");
    }
    else if (score == 3)
    {
        printf("Strong password\n");
    }
    else if (score == 4)
    {
        printf("Very strong password\n");
    }
    
    return 0;
}