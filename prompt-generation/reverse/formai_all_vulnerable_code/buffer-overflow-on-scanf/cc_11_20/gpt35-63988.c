//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Function to check password strength
void passwordStrengthChecker(char password[]){
    int length = strlen(password);
    int hasUppercase = 0, hasLowercase = 0, hasNumber = 0, hasSpecialChar = 0;
    
    //Loop to check each character of the password
    for(int i=0; i<length; i++){
        char c = password[i];
        if(isdigit(c)){
            hasNumber = 1;
        }
        else if(isupper(c)){
            hasUppercase = 1;
        }
        else if(islower(c)){
            hasLowercase = 1;
        }
        else{
            hasSpecialChar = 1;
        }
    }
    
    //Determining the password strength
    if(length < 8){
        printf("Password is too short. It should be at least 8 characters long.\n");
    }
    else if(!hasUppercase && !hasLowercase && !hasSpecialChar){
        printf("Password should contain at least one uppercase letter, one lowercase letter and one special character.\n");
    }
    else if(!hasUppercase && !hasNumber && !hasSpecialChar){
        printf("Password should contain at least one uppercase letter, one number and one special character.\n");
    }
    else if(!hasLowercase && !hasNumber && !hasSpecialChar){
        printf("Password should contain at least one lowercase letter, one number and one special character.\n");
    }
    else if(!hasUppercase && !hasLowercase && !hasNumber){
        printf("Password should contain at least one uppercase letter, one lowercase letter and one number.\n");
    }
    else if(!hasUppercase){
        printf("Password should contain at least one uppercase letter.\n");
    }
    else if(!hasLowercase){
        printf("Password should contain at least one lowercase letter.\n");
    }
    else if(!hasNumber){
        printf("Password should contain at least one number.\n");
    }
    else if(!hasSpecialChar){
        printf("Password should contain at least one special character.\n");
    }
    else{
        printf("Password strength is good!\n");
    }
}

int main(){
    char password[50];
    
    printf("Enter your Password:");
    scanf("%s", password);
    
    passwordStrengthChecker(password);
    
    return 0;
}