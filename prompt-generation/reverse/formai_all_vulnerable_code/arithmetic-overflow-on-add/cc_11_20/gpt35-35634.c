//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char password[50];
    int length, uppercase, lowercase, digit, symbol, score=0;

    printf("Enter your password: ");
    fgets(password, 50, stdin);

    length = strlen(password)-1;

    for(int i=0;i<length;i++)
    {
        if(isupper(password[i]))
            uppercase++;
        else if(islower(password[i]))
            lowercase++;
        else if(isdigit(password[i]))
            digit++;
        else
            symbol++;
    }

    //Check length
    if(length>=8)
        score++;
    else
        printf("Password too short, it must contain at least 8 characters\n");

    //Check uppercase
    if(uppercase>=1)
        score++;
    else
        printf("Password must contain at least 1 uppercase letter\n");

    //Check lowercase
    if(lowercase>=1)
        score++;
    else
        printf("Password must contain at least 1 lowercase letter\n");

    //Check digit
    if(digit>=1)
        score++;
    else
        printf("Password must contain at least 1 digit\n");

    //Check symbol
    if(symbol>=1)
        score++;
    else
        printf("Password must contain at least 1 special symbol\n");

    //Check score
    if(score==5)
        printf("Password is strong\n");
    else
        printf("Password is weak\n");

    return 0;
}