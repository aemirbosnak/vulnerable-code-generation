//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: irregular
#include <stdio.h>
#include <string.h>

// Function to check password strength
int passwordStrength(char password[])
{
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;
 
    // Checking password length
    if(length < 8)
        return 0; // Minimum length should be 8
 
    // Checking for uppercase, lowercase and digits
    for(int i = 0; i < length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;
        else if(password[i] >= 'a' && password[i] <= 'z')
            lowercase++;
        else if(password[i] >= '0' && password[i] <= '9')
            digits++;
        else
            special++;
    }
 
    // Checking for password complexity
    if(uppercase > 0 && lowercase > 0 && digits > 0 && special > 0)
        return 4; // Complex Password
    else if(uppercase > 0 && lowercase > 0 && digits > 0)
        return 3; // Good Password
    else if(uppercase > 0 && lowercase > 0)
        return 2; // Weak Password
    else
        return 1; // Very Weak Password
}

int main()
{
    char password[100];
    
    printf("Welcome to the Password Strength Checker\n");
    printf("Please enter your password: ");
    scanf("%s", password);
    
    switch(passwordStrength(password))
    {
        case 1:
            printf("Your password is very weak.\n");
            break;
        
        case 2:
            printf("Your password is weak.\n");
            break;
        
        case 3:
            printf("Your password is good.\n");
            break;
        
        case 4:
            printf("Your password is complex.\n");
            break;
        
        default:
            printf("Invalid password.\n");
    }
    
    return 0;
}