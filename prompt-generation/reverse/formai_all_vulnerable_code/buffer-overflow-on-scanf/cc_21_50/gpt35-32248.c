//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include<stdio.h>

int main(){

    char password[50];
    int length=0, upper=0, lower=0, number=0, special=0, score=0;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    //Calculating Length of password
    while(password[length] != '\0'){
        length++;
    }

    //Checking for Uppercase, Lowercase, Numbers and Special Characters
    for(int i=0; i<length; i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            upper=1;
        }
        if(password[i] >= 'a' && password[i] <= 'z'){
            lower=1;
        }
        if(password[i] >= '0' && password[i] <= '9'){
            number=1;
        }
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*'){
            special=1;
        }
    }

    //Calculating Strength
    if(length >= 8){
        score+=10;
    }
    if(upper == 1 && lower == 1){
        score+=10;
    }
    if(number == 1 && special == 1){
        score+=10;
    }

    //Giving Feedback
    printf("\nChecking password strength....\n");
    if(score == 0){
        printf("Oh dear! This password is extremely weak. Please try again!\n");
    }
    else if(score > 0 && score <= 20){
        printf("This password is weak. Please try again!\n");
    }
    else if(score > 20 && score <= 40){
        printf("This password is okay. You can do better.\n");
    }
    else if(score > 40 && score < 60){
        printf("This password is good!\n");
    }
    else if(score >= 60 && score < 100){
        printf("Wow! This password is very strong!\n");
    }
    else if(score == 100){
        printf("Congratulations! This password is nearly impossible to crack!\n");
    }

    printf("\nThank you for using the Password Strength Checker. Now go and update your password!\n");
    return 0;
}