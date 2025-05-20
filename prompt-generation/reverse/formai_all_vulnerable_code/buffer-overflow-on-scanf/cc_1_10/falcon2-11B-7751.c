//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include<stdio.h>
#include<string.h>

//function to check password strength
int checkPasswordStrength(char* password){
    int minLength = 8; // minimum length of password
    int upperCase = 0; // count of uppercase letters
    int lowerCase = 0; // count of lowercase letters
    int digits = 0; // count of digits
    int specialChar = 0; // count of special characters
    
    // iterate through password characters
    for(int i=0; password[i]!='\0'; i++){
        if(isupper(password[i])){
            upperCase++;
        }
        else if(islower(password[i])){
            lowerCase++;
        }
        else if(isdigit(password[i])){
            digits++;
        }
        else if(isalnum(password[i])){
            specialChar++;
        }
    }
    
    // check password strength
    if(strlen(password) < minLength){
        printf("Password is too short\n");
        return 0;
    }
    if(upperCase < 1){
        printf("Password must contain at least one uppercase letter\n");
        return 0;
    }
    if(lowerCase < 1){
        printf("Password must contain at least one lowercase letter\n");
        return 0;
    }
    if(digits < 1){
        printf("Password must contain at least one digit\n");
        return 0;
    }
    if(specialChar < 1){
        printf("Password must contain at least one special character\n");
        return 0;
    }
    
    printf("Password strength is strong\n");
    return 1;
}

int main(){
    char password[50];
    
    printf("Enter password: ");
    scanf("%s", password);
    
    if(checkPasswordStrength(password)){
        printf("Password strength is strong\n");
    }
    else{
        printf("Password strength is weak\n");
    }
    
    return 0;
}