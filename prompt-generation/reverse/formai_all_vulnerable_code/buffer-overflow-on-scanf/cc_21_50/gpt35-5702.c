//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void main()
{
    char password[30];
    int i, digit=0, upper=0, lower=0, special=0;
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for(i=0; password[i]!='\0'; i++)
    {
        if(isdigit(password[i]))
            digit++;
        else if(isupper(password[i]))
            upper++;
        else if(islower(password[i]))
            lower++;
        else
            special++;
    }
    
    if(i>=8 && i<=15)
    {
        if(digit>0 && upper>0 && lower>0 && special>0)
            printf("Your password is strong and surreal like Dali's world!");
        else if(digit>0 && upper>0 && lower>0)
            printf("Your password is strong but not surreal enough.");
        else if(digit>0 && upper>0 && special>0)
            printf("Your password is strong but not surreal enough.");
        else if(digit>0 && lower>0 && special>0)
            printf("Your password is strong but not surreal enough.");
        else if(upper>0 && lower>0 && special>0)
            printf("Your password is strong but not surreal enough.");
        else if(digit>0 && upper>0)
            printf("Your password is strong but not surreal enough.");
        else if(digit>0 && lower>0)
            printf("Your password is strong but not surreal enough.");
        else if(digit>0 && special>0)
            printf("Your password is strong but not surreal enough.");
        else if(upper>0 && lower>0)
            printf("Your password is strong but not surreal enough.");
        else if(upper>0 && special>0)
            printf("Your password is strong but not surreal enough.");
        else if(lower>0 && special>0)
            printf("Your password is strong but not surreal enough.");
        else
            printf("Your password is weak and not surreal enough.");
    }
    else
        printf("Your password length is not surreal enough.");
}