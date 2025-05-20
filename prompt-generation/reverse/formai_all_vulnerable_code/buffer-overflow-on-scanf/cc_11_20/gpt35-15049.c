//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define the password checker function
void password_checker(char* password) {
    
    // define the password length variable
    int length = strlen(password);
    
    // define the variables to track the password strength
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;
    
    // loop through each character in the password
    for (int i = 0; i < length; i++) {
        
        // check if the character is a lowercase letter
        if (islower(password[i])) {
            lower = 1;
        }
        
        // check if the character is an uppercase letter
        else if (isupper(password[i])) {
            upper = 1;
        }
        
        // check if the character is a digit
        else if (isdigit(password[i])) {
            digit = 1;
        }
        
        // check if the character is a special character
        else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$') {
            special = 1;
        }
    }
    
    // check the password strength
    if (length >= 8 && upper && lower && digit && special) {
        printf("Congratulations! Your password is very strong.\n");
    }
    else if (length >= 8 && upper && lower && digit) {
        printf("Congratulations! Your password is strong.\n");
    }
    else if (length >= 8 && upper && lower) {
        printf("Your password is good.\n");
    }
    else {
        printf("Your password is weak. Please consider a stronger password.\n");
    }
    
}

// define the main function
int main() {
    
    // define the password variable
    char password[100];
    
    // prompt the user for a password
    printf("Please enter your password: ");
    scanf("%s", password);
    
    // output the password strength
    password_checker(password);
    
    // exit the program
    return 0;
}