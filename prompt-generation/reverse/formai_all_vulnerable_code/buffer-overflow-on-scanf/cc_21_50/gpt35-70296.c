//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
// Welcome to the C Password Strength Checker!

#include<stdio.h>
#include<string.h>

void main(){

    // Initializing variables
    char password[50];
    int password_strength = 0;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    // Greeting message
    printf("\nWelcome to the C Password Strength Checker!\n\n");

    // Taking input from user
    printf("Please enter your password: ");
    scanf("%s",password);

    // Calculating strength of password
    for(int i=0; i<strlen(password); i++){

        // Checking for uppercase letters
        if(password[i]>='A' && password[i]<='Z'){
            uppercase_count++;
        }

        // Checking for lowercase letters
        else if(password[i]>='a' && password[i]<='z'){
            lowercase_count++;
        }

        // Checking for digits
        else if(password[i]>='0' && password[i]<='9'){
            digit_count++;
        }

        // Checking for special characters
        else{
            special_count++;
        }
    }

    // Calculating strength of password based on the criteria
    if(strlen(password)<8){
        password_strength = -1;
    }
    else if(uppercase_count>0 && lowercase_count>0 && digit_count>0 && special_count>0){
        password_strength = 4;
    }
    else if((uppercase_count>0 && lowercase_count>0) || (lowercase_count>0 && digit_count>0) || (digit_count>0 && special_count>0)){
        password_strength = 3;
    }
    else if(uppercase_count>0 || lowercase_count>0 || digit_count>0){
        password_strength = 2;
    }
    else{
        password_strength = 1;
    }

    // Providing feedback to user
    printf("\nYour password strength is: ");

    // Using mind-bending style to give feedback to user
    switch(password_strength){
        case -1: printf("You call that a password? It's almost as weak as tofu."); break;
        case 1: printf("Your password is weaker than a wet noodle. Can you try harder?"); break;
        case 2: printf("Your password is okay-ish, but could be better. Add some special characters to make it better!"); break;
        case 3: printf("Your password is pretty strong, but could use some more complexity. Add some uppercase letters to make it stronger!"); break;
        case 4: printf("Wow! Your password is as strong as an ox. You clearly know what you're doing!"); break;
        default: printf("I'm sorry, I couldn't analyze that password. Mind trying again?"); break;
    }

    printf("\n\nThank you for using the C Password Strength Checker!");

}