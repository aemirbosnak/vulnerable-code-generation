//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define LOWER_CASE 1
#define UPPER_CASE 2
#define NUMBER 3
#define SPECIAL_CHAR 4
#define LENGTH 5

//function to check if character is lower case
int isLower(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return 1;
    else
        return 0;
}

//function to check if character is upper case
int isUpper(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return 1;
    else
        return 0;
}

//function to check if character is a number
int isNumber(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

//function to check if character is a special character
int isSpecial(char ch)
{
    if(ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '&' || ch == '*')
        return 1;
    else
        return 0;
}

//main function to check password strength
void checkPassword(char password[])
{
    int length = strlen(password);
    int lowerCount = 0;
    int upperCount = 0;
    int numberCount = 0;
    int specialCount = 0;

    //loop through each character in password
    for(int i=0; i<length; i++)
    {
        //check if character is lower case
        if(isLower(password[i]))
            lowerCount++;

        //check if character is upper case
        else if(isUpper(password[i]))
            upperCount++;

        //check if character is a number
        else if(isNumber(password[i]))
            numberCount++;

        //check if character is a special character
        else if(isSpecial(password[i]))
            specialCount++;
    }

    //print the password strength
    printf("Password Strength: ");
    if(lowerCount > 0)
        printf("Lower case letter(s) found. ");
    if(upperCount > 0)
        printf("Upper case letter(s) found. ");
    if(numberCount > 0)
        printf("Number(s) found. ");
    if(specialCount > 0)
        printf("Special character(s) found. ");
    if(length >= 8)
        printf("Password length is at least 8 characters. ");
    else
        printf("Password length is less than 8 characters. ");
}

//main function
int main()
{
    char password[100];

    //take input from user
    printf("Enter password: ");
    scanf("%s", password);

    //check password strength
    checkPassword(password);

    return 0;
}