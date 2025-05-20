//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: excited
//Welcome to the Password Strength Checker!

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char password[50];
    int length, hasUpper=0, hasLower=0, hasNumber=0, hasSpecial=0, strength=0;
    //Initialize values

    printf("Enter your password: ");
    scanf("%s", password);
    //Take password as input

    length = strlen(password);
    //Get password length

    for(int i=0; i<length; i++)
    {
        if(password[i]>='A' && password[i]<='Z')
            hasUpper = 1;
        if(password[i]>='a' && password[i]<='z')
            hasLower = 1;
        if(password[i]>='0' && password[i]<='9')
            hasNumber = 1;
        if(password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='_')
            hasSpecial = 1;
    }
    //Check password for upper case, lower case, numbers, and special characters

    strength = hasUpper + hasLower + hasNumber + hasSpecial;
    //Calculate password strength

    if(strength<2) //Weak Password
    {
        printf("\nYour password is weak.\n");
        if(length<6)
            printf("Your password should have at least 6 characters.\n");
        if(!hasUpper)
            printf("Your password should contain at least one uppercase letter.\n");
        if(!hasLower)
            printf("Your password should contain at least one lowercase letter.\n");
        if(!hasNumber)
            printf("Your password should contain at least one number.\n");
        if(!hasSpecial)
            printf("Your password should contain at least one special character (@, #, $, _).\n");
    }
    else if(strength<4) //Moderate Password
    {
        printf("\nYour password is moderate.\n");
        if(length<8)
            printf("Your password should have at least 8 characters.\n");
        if(!hasUpper)
            printf("Your password should contain at least one uppercase letter.\n");
        if(!hasLower)
            printf("Your password should contain at least one lowercase letter.\n");
        if(!hasNumber)
            printf("Your password should contain at least one number.\n");
        if(!hasSpecial)
            printf("Your password should contain at least one special character (@, #, $, _).\n");
    }
    else //Strong Password
    {
        printf("\nCongratulations! Your password is strong!\n");
        if(length<10)
            printf("However, your password can be even stronger if it has at least 10 characters.\n");
    }

    return 0;
}