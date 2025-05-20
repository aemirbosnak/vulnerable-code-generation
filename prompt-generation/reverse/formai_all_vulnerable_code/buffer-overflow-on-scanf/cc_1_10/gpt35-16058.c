//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    //Welcome message
    printf("Welcome to Password Strength Checker!\n");

    //Variable declaration
    char password[50];
    int length, i, upper = 0, lower = 0, digit = 0, special = 0;

    //Prompt user for input
    printf("Please enter your password: ");
    scanf("%s", password);

    //Calculate length of password
    length = strlen(password);

    //Check strength of password
    for(i=0; i<length; i++){
        //Check for uppercase letters
        if(isupper(password[i])){
            upper++;
        }
        //Check for lowercase letters
        else if(islower(password[i])){
            lower++;
        }
        //Check for digits
        else if(isdigit(password[i])){
            digit++;
        }
        //Check for special characters
        else{
            special++;
        }
    }

    //Print results of password strength check
    if(length<8){
        printf("Your password is weak.\n");
        printf("Password length must be at least 8 characters.\n");
    }
    else if(upper<1 || lower<1 || digit<1 || special<1){
        printf("Your password is weak.\n");
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
    else{
        printf("Your password is strong!\n");
    }

    //Exit message
    printf("Thank you for using Password Strength Checker!\n");

    return 0;
}