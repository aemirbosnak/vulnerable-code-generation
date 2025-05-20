//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
    char password[100];
    int length, hasLowercase, hasUppercase, hasNumbers, hasSpecial;
    length = hasLowercase = hasUppercase = hasNumbers = hasSpecial = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Checking for lowercase letters
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowercase = 1;
            break;
        }
    }

    // Checking for uppercase letters
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = 1;
            break;
        }
    }

    // Checking for numbers
    for(int i=0; i<length; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            hasNumbers = 1;
            break;
        }
    }

    // Checking for special characters
    for(int i=0; i<length; i++)
    {
        if(!(password[i] >= '0' && password[i] <= '9') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= 'A' && password[i] <= 'Z'))
        {
            hasSpecial = 1;
            break;
        }
    }

    // Check if the password is a strong password or not
    if(length >= 8 && hasLowercase && hasUppercase && hasNumbers && hasSpecial)
    {
        printf("Password strength: SUPER STRONG! You're basically a cyborg!\n");
    }
    else if(length >= 8 && hasLowercase && hasUppercase && hasNumbers)
    {
        printf("Password strength: STRONG! You could give Superman a run for his money!\n");
    }
    else if(length >= 8 && (hasLowercase || hasUppercase) && hasNumbers)
    {
        printf("Password strength: AVERAGE! You're just like the rest of us!\n");
    }
    else if(length >= 6 && (hasLowercase || hasUppercase) && (hasNumbers || hasSpecial))
    {
        printf("Password strength: WEAK! You might want to consider making your password stronger.\n");
    }
    else
    {
        printf("Password strength: PATHETIC! You might as well not have a password at all!\n");
        printf("Here's a better password for you: 12345\n");
    }

    return 0;
}