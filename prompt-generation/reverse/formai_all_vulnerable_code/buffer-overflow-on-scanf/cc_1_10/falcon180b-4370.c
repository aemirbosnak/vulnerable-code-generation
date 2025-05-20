//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 20

//function to check if string contains only alphabets
int isAlphabet(char* str)
{
    int i=0;
    while(str[i])
    {
        if(!isalpha(str[i]))
            return 0;
        i++;
    }
    return 1;
}

//function to check if string contains both uppercase and lowercase letters
int containsBothCases(char* str)
{
    int i=0;
    while(str[i])
    {
        if(isupper(str[i]))
            return 1;
        i++;
    }
    return 0;
}

//function to check if string contains at least one special character
int containsSpecialChar(char* str)
{
    int i=0;
    while(str[i])
    {
        if(!isalnum(str[i]))
            return 1;
        i++;
    }
    return 0;
}

//function to check if string contains at least one digit
int containsDigit(char* str)
{
    int i=0;
    while(str[i])
    {
        if(isdigit(str[i]))
            return 1;
        i++;
    }
    return 0;
}

//function to check password strength
int checkPasswordStrength(char* str)
{
    int length=strlen(str);
    if(length>MAX_LENGTH)
        return 0;
    if(!isAlphabet(str))
        return 0;
    if(!containsBothCases(str))
        return 0;
    if(!containsSpecialChar(str))
        return 0;
    if(!containsDigit(str))
        return 0;
    return 1;
}

//main function
int main()
{
    char password[MAX_LENGTH];
    int strength;
    int i=0;
    printf("Enter password: ");
    scanf("%s",password);
    strength=checkPasswordStrength(password);
    if(strength==1)
        printf("Password is strong!\n");
    else
    {
        printf("Password is weak!\n");
        printf("The password should be at least 8 characters long and must contain both uppercase and lowercase letters, at least one special character and at least one digit.\n");
    }
    return 0;
}