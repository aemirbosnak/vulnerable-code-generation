//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check password strength
bool check_password_strength(char password[])
{
    int len = strlen(password);

    // Set the flags to false initially
    bool upper_flag = false;
    bool lower_flag = false;
    bool digit_flag = false;
    bool special_flag = false;

    // Loop through each character of the password
    for(int i=0; i<len; i++)
    {
        // Check for uppercase letters
        if(password[i]>='A' && password[i]<='Z')
        {
            upper_flag = true;
        }

        // Check for lowercase letters
        if(password[i]>='a' && password[i]<='z')
        {
            lower_flag = true;
        }

        // Check for digits
        if(password[i]>='0' && password[i]<='9')
        {
            digit_flag = true;
        }

        // Check for special characters
        if(strchr("~!@#$%^&*()_+{}[]|\\:;'<>,.?/\"", password[i])!=NULL)
        {
            special_flag = true;
        }
    }

    // Check for password length
    if(len<8)
    {
        printf("Password length is not enough.\n");
        return false;
    }

    // Check for all criteria
    if(upper_flag && lower_flag && digit_flag && special_flag)
    {
        printf("Strong password.\n");
        return true;
    }
    else
    {
        printf("Password is not strong enough.\n");
        return false;
    }
}

int main()
{
    char password[50];
    printf("Enter the password : ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}