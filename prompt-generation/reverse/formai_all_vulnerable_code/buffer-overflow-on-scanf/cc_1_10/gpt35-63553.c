//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool hasLowercase(char* password)
{
    for(int i = 0; i < strlen(password); i++)
    {
        if(islower(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool hasUppercase(char* password)
{
    for(int i = 0; i < strlen(password); i++)
    {
        if(isupper(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool hasNumber(char* password)
{
    for(int i = 0; i < strlen(password); i++)
    {
        if(isdigit(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool hasSpecialCharacter(char* password)
{
    for(int i = 0; i < strlen(password); i++)
    {
        if(!isalnum(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool isLongEnough(char* password)
{
    int length = strlen(password);
    if(length >= 8 && length <= 16)
    {
        return true;
    }
    return false;
}

void printPasswordStrength(char* password)
{
    printf("Password strength: ");
    if(!isLongEnough(password))
    {
        printf("Too short/long\n");
        return;
    }
    if(!hasLowercase(password))
    {
        printf("Weak\n");
        printf("- Include lowercase letters\n");
        return;
    }
    if(!hasUppercase(password))
    {
        printf("Weak\n");
        printf("- Include uppercase letters\n");
        return;
    }
    if(!hasNumber(password))
    {
        printf("Weak\n");
        printf("- Include numbers\n");
        return;
    }
    if(!hasSpecialCharacter(password))
    {
        printf("Weak\n");
        printf("- Include special characters\n");
        return;
    }
    printf("Strong\n");
}

int main()
{
    char password[128];
    printf("Enter password: ");
    scanf("%s", password);
    printPasswordStrength(password);
    return 0;
}