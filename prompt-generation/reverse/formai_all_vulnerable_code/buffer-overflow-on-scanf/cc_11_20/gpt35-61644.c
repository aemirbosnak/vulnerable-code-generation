//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_password_strength(char *password);

int main(){

    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch(strength){
        case 0:
            printf("Your password is too weak\n");
            break;
        case 1:
            printf("Your password is weak\n");
            break;
        case 2:
            printf("Your password is of moderate strength\n");
            break;
        case 3:
            printf("Your password is strong\n");
            break;
        case 4:
            printf("Your password is very strong\n");
            break;
        default:
            printf("Invalid password strength\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password){

    int score = 0;

    //check length of password
    int len = strlen(password);
    if(len < 8){
        return 0;
    }else if(len >= 8 && len <= 10){
        score++;
    }else if(len > 10){
        score += 2;
    }

    //check if password contains uppercase letters
    int has_uppercase = 0;
    for(int i = 0; i < len; i++){
        if(isupper(password[i])){
            has_uppercase = 1;
            break;
        }
    }

    if(has_uppercase){
        score++;
    }

    //check if password contains lowercase letters
    int has_lowercase = 0;
    for(int i = 0; i < len; i++){
        if(islower(password[i])){
            has_lowercase = 1;
            break;
        }
    }

    if(has_lowercase){
        score++;
    }

    //check if password contains digits
    int has_digits = 0;
    for(int i = 0; i < len; i++){
        if(isdigit(password[i])){
            has_digits = 1;
            break;
        }
    }

    if(has_digits){
        score++;
    }

    //check if password contains special characters
    int has_special = 0;
    for(int i = 0; i < len; i++){
        if(!isalnum(password[i])){
            has_special = 1;
            break;
        }
    }

    if(has_special){
        score += 2;
    }

    return score;
}