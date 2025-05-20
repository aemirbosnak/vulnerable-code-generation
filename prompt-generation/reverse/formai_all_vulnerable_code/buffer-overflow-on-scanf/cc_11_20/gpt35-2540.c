//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
    int i,n;
    int upper=0,lower=0,digit=0,special=0;
    int strength=0;
    char password[20];

    printf("Enter your password (max 20 characters): ");
    scanf("%s",password);//Scan the password character by character

    n=strlen(password);

    if(n<8)//Check if password length is less than 8
    {
        printf("Password is too weak, it must have at least 8 characters.\n");
        return;
    }

    for(i=0;i<n;i++)//Loop through each character and categorize it
    {
        if(isupper(password[i]))
            upper++;
        else if(islower(password[i]))
            lower++;
        else if(isdigit(password[i]))
            digit++;
        else
            special++;
    }

    if(upper>0)//If there is at least one uppercase letter
    {
        strength++;//Increase strength by 1
    }
    if(lower>0)//If there is at least one lowercase letter
    {
        strength++;//Increase strength by 1
    }
    if(digit>0)//If there is at least one digit
    {
        strength++;//Increase strength by 1
    }
    if(special>0)//If there is at least one special character
    {
        strength++;//Increase strength by 1
    }

    if(strength<2)//If the password strength is less than 2
    {
        printf("Password is weak, it must have at least 2 of the following: uppercase letter, lowercase letter, digit, special character.\n");
        return;
    }

    if(strength==2)//If the password strength is 2
    {
        printf("Password is moderate, it has at least 2 of the following: uppercase letter, lowercase letter, digit, special character.\n");
        return;
    }

    if(strength>2)//If the password strength is greater than 2
    {
        printf("Password is strong, it has at least 3 of the following: uppercase letter, lowercase letter, digit, special character.\n");
        return;
    }
}