//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to check if the password contains only letters
int onlyLetters(char pass[]){
    int i;
    for(i=0; pass[i] != '\0'; i++){
        if(!isalpha(pass[i])) 
            return 0;
    }
    return 1;
}

//function to check if the password contains only numbers
int onlyNumbers(char pass[]){
    int i;
    for(i=0; pass[i] !='\0'; i++){
        if(!isdigit(pass[i])) 
            return 0;
    }
    return 1;
}

//function to check if the password contains only special characters
int onlySpecial(char pass[]){
    int i;
    for(i=0; pass[i] !='\0'; i++){
        if(isalnum(pass[i])) 
            return 0;
    }
    return 1;
}

//function to check the strength of the password
void passwordStrength(char pass[]){
    int strength = 0;
    int length = strlen(pass);
    
    //if the password is less than 8 characters long
    if(length < 8){
        printf("Weak Password!\n");
        strength = 1;
    }
    else{
        //if the password contains only letters
        if(onlyLetters(pass)){
            printf("Weak Password!\n");
            strength = 2;
        }
        //if the password contains only numbers
        else if(onlyNumbers(pass)){
            printf("Weak Password!\n");
            strength = 3;
        }
        //if the password contains only special characters
        else if(onlySpecial(pass)){
            printf("Weak Password!\n");
            strength = 4;
        }
        //if the password contains a combination of letters, numbers and special characters
        else{
            printf("Strong Password!\n");
            strength = 5;
        }
    }
    
    //printing suggestions to improve passwords
    if(strength == 1){
        printf("Your password should be at least 8 characters long.\n");
        printf("Try using a combination of letters, numbers and special characters.\n");
    }
    else if(strength == 2){
        printf("Try using numbers and special characters in your password.\n");
    }
    else if(strength == 3){
        printf("Try using letters and special characters in your password.\n");
    }
    else if(strength == 4){
        printf("Try using letters and numbers in your password.\n");
    }
}

//main function
int main(){
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    passwordStrength(password);
    return 0;
}