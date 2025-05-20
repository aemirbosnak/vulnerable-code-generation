//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: portable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)
{
    char password[50];
    printf("Enter the Password that you want to check the strength of:\n");
    scanf("%s", password);
    int length = strlen(password);
    int upper=0, lower=0, digit=0, symbol=0, strength=0;

    for(int i=0; i<length; i++) 
    {
        char ch = password[i];
        if(isupper(ch))
            upper=1;
        else if(islower(ch))
            lower=1;
        else if(isdigit(ch))
            digit=1;
        else
            symbol=1;
    }

    int hasLowerUpper = lower && upper; 
    int hasDigit = digit;
    int hasSymbol = symbol;

    if(length < 8)
    {
        printf("Weak Password\n");
    }
    else if(length<12)
    {
        strength++;
    }
    else if(length>=12)
    {
        strength+=2;
    }

    if(hasLowerUpper)
    {
        strength++;
    }
    if(hasDigit)
    {
        strength+=2;
    }
    if(hasSymbol)
    {
        strength+=2;
    }

    if(strength >= 5) 
    {
        printf("Strong Password\n");
    }
    else if(strength>=3 && strength<5)
    {
        printf("Moderate Password\n");
    }
    else
    {
        printf("Weak Password\n");
    }
    return 0;
}