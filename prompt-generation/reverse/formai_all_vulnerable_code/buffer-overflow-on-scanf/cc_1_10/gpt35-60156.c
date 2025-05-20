//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include<stdio.h>
#include<string.h>

// Function to check password strength
void passStrengthChecker(char password[]) 
{
    int length = strlen(password);
    int i, upper = 0, lower = 0, number = 0, special_char = 0;

    for (i = 0; i < length; i++) 
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            upper++;

        else if (password[i] >= 'a' && password[i] <= 'z')
            lower++;

        else if (password[i] >= '0' && password[i] <= '9')
            number++;

        else
            special_char++;
    }

    if (length < 8 || upper == 0 || lower == 0 || number == 0 || special_char == 0) 
    {
        printf("Oops! The password is weak. Try another one.\n");
        
        if (length < 8)
            printf("Password should contain minimum 8 characters.\n");

        if (upper == 0)
            printf("Password should contain atleast one uppercase letter.\n");

        if (lower == 0)
            printf("Password should contain atleast one lowercase letter.\n");

        if (number == 0)
            printf("Password should contain atleast one number.\n");

        if (special_char == 0)
            printf("Password should contain atleast one special character.\n");
    }

    else
        printf("Congratulations! The password is strong enough.\n");
}

int main() 
{
    char password[50];
    printf("Welcome to the Password Strength Checker program!\n");
    printf("Please enter your password: ");
    scanf("%s", password);
    passStrengthChecker(password);
    return 0;
}