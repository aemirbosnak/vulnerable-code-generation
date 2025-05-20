//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char password[20];
    int length, upper, lower, digits, special = 0;
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for(int i=0; i<length; i++) {
        // Checking for uppercase letters
        if(isupper(password[i])) {
            upper = 1;
        }
        // Checking for lowercase letters
        else if(islower(password[i])) {
            lower = 1;
        }
        // Checking for digits
        else if(isdigit(password[i])) {
            digits = 1;
        }
        // Checking for special characters
        else {
            special = 1;
        }
    }
    
    // Checking the password strength based on the above conditions
    if(length < 8 || length > 16) {
        printf("Password length should be between 8 and 16 characters.");
    }
    else if(upper == 0) {
        printf("Password should contain at least one uppercase letter.");
    }
    else if(lower == 0) {
        printf("Password should contain at least one lowercase letter.");
    }
    else if(digits == 0) {
        printf("Password should contain at least one digit.");
    }
    else if(special == 0) {
        printf("Password should contain at least one special character.");
    }
    else {
        printf("Your password is strong!");
    }
    
    return 0;
}