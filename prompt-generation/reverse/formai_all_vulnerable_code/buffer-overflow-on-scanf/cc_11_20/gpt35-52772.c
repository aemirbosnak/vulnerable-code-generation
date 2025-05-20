//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: futuristic
#include<stdio.h>

int containsLower(char* password){
    for(int i=0;password[i]!='\0';i++){
        if(password[i]>='a' && password[i]<='z'){
            return 1;
        }
    }
    return 0;
}

int containsUpper(char* password){
    for(int i=0;password[i]!='\0';i++){
        if(password[i]>='A' && password[i]<='Z'){
            return 1;
        }
    }
    return 0;
}

int containsDigit(char* password){
    for(int i=0;password[i]!='\0';i++){
        if(password[i]>='0' && password[i]<='9'){
            return 1;
        }
    }
    return 0;
}

int containsSpecial(char* password){
    for(int i=0;password[i]!='\0';i++){
        if((password[i]>=33 && password[i]<=47) || (password[i]>=58 && password[i]<65) || (password[i]>=91 && password[i]<=96) || (password[i]>=123 && password[i]<=126)){
            return 1;
        }
    }
    return 0;
}

void validatePassword(char* password){
    int lower = containsLower(password);
    int upper = containsUpper(password);
    int digit = containsDigit(password);
    int special = containsSpecial(password);
    int strength = 0;
    
    // check for strong password
    if(lower == 1 && upper == 1 && digit == 1 && special == 1 && strlen(password) >= 8){
        strength = 4; // strong
    } 
    // check for medium password
    else if((lower == 1 && upper == 1 && digit == 1 && special == 0 && strlen(password) >= 6) || (lower == 1 && upper == 1 && digit == 0 && special == 1 && strlen(password) >= 6) || (lower == 1 && upper == 0 && digit == 1 && special == 1 && strlen(password) >= 6) || (lower == 0 && upper == 1 && digit == 1 && special == 1 && strlen(password) >= 6)){
        strength = 3; // medium
    }
    // check for weak password
    else if((lower == 1 && upper == 1 && digit == 0 && special == 0 && strlen(password) >= 4) || (lower == 1 && upper == 0 && digit == 1 && special == 0 && strlen(password) >= 4) || (lower == 0 && upper == 1 && digit == 1 && special == 0 && strlen(password) >= 4) || (lower == 0 && upper == 0 && digit == 1 && special == 1 && strlen(password) >= 4)){
        strength = 2; // weak
    }
    // check for very weak password
    else if((lower == 1 && upper == 0 && digit == 0 && special == 0 && strlen(password) >= 2) || (lower == 0 && upper == 1 && digit == 0 && special == 0 && strlen(password) >= 2) || (lower == 0 && upper == 0 && digit == 1 && special == 0 && strlen(password) >= 2) || (lower == 0 && upper == 0 && digit == 0 && special == 1 && strlen(password) >= 2)){
        strength = 1; // very weak
    }
    
    // print the strength of password
    switch(strength){
        case 1:
            printf("Your password is very weak!\n");
            break;
        case 2:
            printf("Your password is weak!\n");
            break;
        case 3:
            printf("Your password is medium!\n");
            break;
        case 4:
            printf("Your password is strong!\n");
            break;
        default:
            printf("Invalid password!\n");
            break;
    }
}

int main(){
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);
    
    // check password strength
    validatePassword(password);
    
    return 0;
}