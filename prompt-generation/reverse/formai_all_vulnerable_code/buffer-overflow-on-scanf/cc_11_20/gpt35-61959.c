//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>

int checkPasswordStrength(char password[]) {
    int len = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    
    // check if password has minimum length of 8 characters
    if(len < 8) {
        return 0; // return 0 if password is weak
    }
    
    // iterate through the password characters
    for(int i=0; i<len; i++) {
        char ch = password[i];
        if(ch >= 'a' && ch <= 'z') {
            hasLower = 1; // password has lowercase characters
        } else if(ch >= 'A' && ch <= 'Z') {
            hasUpper = 1; // password has uppercase characters
        } else if(ch >= '0' && ch <= '9') {
            hasDigit = 1; // password has digits
        } else {
            hasSpecial = 1; // password has special characters
        }
    }
    
    // check if password has at least one character from each category
    if(hasLower && hasUpper && hasDigit && hasSpecial) {
        return 2; // return 2 if password is strong
    } else if((hasLower && hasUpper && hasDigit) || (hasLower && hasUpper && hasSpecial) || (hasLower && hasDigit && hasSpecial) || (hasUpper && hasDigit && hasSpecial)) {
        return 1; // return 1 if password is moderate
    } else {
        return 0; // return 0 if password is weak
    }
}

int main() {
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = checkPasswordStrength(password);
    
    if(strength == 0) {
        printf("Password is weak!\n");
    } else if(strength == 1) {
        printf("Password is moderate!\n");
    } else if(strength == 2) {
        printf("Password is strong!\n");
    }
    
    return 0;
}