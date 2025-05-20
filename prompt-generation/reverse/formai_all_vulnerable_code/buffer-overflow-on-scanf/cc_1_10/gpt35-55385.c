//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool hasUpperCase(char* password)
{
    for(int i=0;i<strlen(password);i++)
    {
        if(isupper(password[i]))
            return true;
    }
    return false;
}

bool hasLowerCase(char* password)
{
    for(int i=0;i<strlen(password);i++)
    {
        if(islower(password[i]))
            return true;
    }
    return false;
}

bool hasDigit(char* password)
{
    for(int i=0;i<strlen(password);i++)
    {
        if(isdigit(password[i]))
            return true;
    }
    return false;
}

bool hasSpecialChar(char* password)
{
    char specialCharArr[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '<', '>', ':', ';', '?', '/'};
    for(int i=0;i<strlen(password);i++)
    {
        for(int j=0;j<27;j++)
        {
            if(password[i] == specialCharArr[j])
                return true;
        }
    }
    return false;
}

bool isLongEnough(char* password)
{
    if(strlen(password) >= 8)
        return true;
    else
        return false;
}

int getPasswordStrength(char* password)
{
    int strength = 0;
    if(hasUpperCase(password))
        strength++;
    if(hasLowerCase(password))
        strength++;
    if(hasDigit(password))
        strength++;
    if(hasSpecialChar(password))
        strength++;
    if(isLongEnough(password))
        strength++;
    return strength;
}

int main()
{
    char password[50];
    printf("Enter a password: ");
    scanf("%s", password);

    int strength = getPasswordStrength(password);

    switch(strength)
    {
        case 1:
            printf("Password is very weak\n");
            break;
        case 2:
            printf("Password is weak\n");
            break;
        case 3:
            printf("Password is moderate\n");
            break;
        case 4:
            printf("Password is strong\n");
            break;
        case 5:
            printf("Password is very strong\n");
            break;
        default:
            printf("Invalid password entered\n");
    }

    return 0;
}