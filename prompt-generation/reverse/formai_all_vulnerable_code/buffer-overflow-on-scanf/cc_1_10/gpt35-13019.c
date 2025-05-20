//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: grateful
#include<stdio.h>
#include<ctype.h>
#include<string.h>

/*
Grateful Password Strength Checker Program
This program is designed to check the strength of a given password.
It evaluates passwords based on the following criteria:
- at least 8 characters long
- contains uppercase letters
- contains lowercase letters
- contains numbers
- contains special characters
*/

int main() {
    char password[100];
    int len, upper = 0, lower = 0, digit = 0, special = 0;
    
    printf("Grateful Password Strength Checker Program\n");
    printf("------------------------------------------\n");
    printf("Enter your password: ");
    scanf("%s", password);
    
    len = strlen(password);
    
    if(len < 8) {   // check if password is at least 8 characters long
        printf("Your password is too short. It must be at least 8 characters long.\n");
        return 0;
    }
    
    for(int i = 0; i < len; i++) {
        if(isupper(password[i]))
            upper = 1;
        else if(islower(password[i]))
            lower = 1;
        else if(isdigit(password[i]))
            digit = 1;
        else
            special = 1;
    }
    
    if(!upper) {
        printf("Your password must contain at least one uppercase letter.\n");
        return 0;   
    }
    
    if(!lower) {
        printf("Your password must contain at least one lowercase letter.\n");
        return 0;
    }
    
    if(!digit) {
        printf("Your password must contain at least one number.\n");
        return 0;
    }
    
    if(!special) {
        printf("Your password must contain at least one special character.\n");
        return 0;
    }
    
    printf("Congratulations! Your password meets all criteria for a strong password.\n");
    
    return 0;
}