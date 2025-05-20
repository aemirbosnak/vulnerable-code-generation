//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main(){
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;
    for(int i = 0; i < length; i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            uppercase++;
        }else if(password[i] >= 'a' && password[i] <= 'z'){
            lowercase++;
        }else if(password[i] >= '0' && password[i] <= '9'){
            digits++;
        }else{
            special++;
        }
    }
    int strength = 0;
    if(lowercase > 0){
        strength++;
    }
    if(uppercase > 0){
        strength++;
    }
    if(digits > 0){
        strength++;
    }
    if(special > 0){
        strength++;
    }
    if(length >= 8){
        strength++;
    }
    if(strength == 1){
        printf("This password is very weak, you need to improve the strength of your password.\n");
    }else if(strength == 2){
        printf("This password is weak, you need to improve the strength of your password.\n");
    }else if(strength == 3){
        printf("This password is medium strength, but you should still improve it.\n");
    }else if(strength == 4){
        printf("This password is strong but a little more improvement could make it better.\n");
    }else if(strength == 5){
        printf("This password is very strong, good job!\n");
    }else{
        printf("You need to choose a password with a minimum of 8 characters.\n");
    }
    return 0;
}