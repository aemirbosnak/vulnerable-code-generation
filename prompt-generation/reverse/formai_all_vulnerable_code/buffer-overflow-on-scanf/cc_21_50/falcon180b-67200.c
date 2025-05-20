//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char password[100];
    int i,j,length,score=0;
    char uppercase=0,lowercase=0,digit=0,special=0;

    //Get password from user
    printf("Enter your password: ");
    scanf("%s",password);

    //Check for password length
    length=strlen(password);

    //Check for uppercase character
    for(i=0;i<length;i++){
        if(isupper(password[i])){
            uppercase=1;
            break;
        }
    }

    //Check for lowercase character
    for(i=0;i<length;i++){
        if(islower(password[i])){
            lowercase=1;
            break;
        }
    }

    //Check for digit character
    for(i=0;i<length;i++){
        if(isdigit(password[i])){
            digit=1;
            break;
        }
    }

    //Check for special character
    for(i=0;i<length;i++){
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?' || password[i] == '/' || password[i] == '^' || password[i] == '&' || password[i] == '~'){
            special=1;
            break;
        }
    }

    //Calculate password strength score
    if(length >= 8){
        score = score + 1;
    }
    if(uppercase){
        score = score + 1;
    }
    if(lowercase){
        score = score + 1;
    }
    if(digit){
        score = score + 1;
    }
    if(special){
        score = score + 1;
    }

    //Print password strength score
    if(score <= 1){
        printf("Weak password");
    }
    else if(score <= 3){
        printf("Medium password");
    }
    else{
        printf("Strong password");
    }

    return 0;
}