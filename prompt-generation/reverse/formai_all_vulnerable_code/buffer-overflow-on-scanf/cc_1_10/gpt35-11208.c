//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function to check if password length is valid
bool checkLength(char* password) {
    int len = strlen(password);
    if(len>=8 && len<=16) {
        return true;
    }
    return false;
}

// Function to check if password contains uppercase letters
bool checkUpperCase(char* password) {
    for(int i=0; i<strlen(password); i++) {
        if(isupper(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if password contains lowercase letters
bool checkLowerCase(char* password) {
    for(int i=0; i<strlen(password); i++) {
        if(islower(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if password contains special characters
bool checkSpecialChar(char* password) {
    for(int i=0; i<strlen(password); i++) {
        if(!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if password contains numeric characters
bool checkNumeric(char* password) {
    for(int i=0; i<strlen(password); i++) {
        if(isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to print a strength meter for the password
void printStrength(char* password) {
    int strength = 0;
    
    if(checkLength(password)) {
        strength += 20;
    }
    if(checkUpperCase(password)) {
        strength += 20;
    }
    if(checkLowerCase(password)) {
        strength += 20;
    }
    if(checkSpecialChar(password)) {
        strength += 20;
    }
    if(checkNumeric(password)) {
        strength += 20;
    }
    
    if(strength == 0) {
        printf("Password is not valid.");
    }
    else if(strength <= 40) {
        printf("Password is weak. Strength: %d/100", strength);
    }
    else if(strength <= 60) {
        printf("Password is average. Strength: %d/100", strength);
    }
    else if(strength <= 80) {
        printf("Password is strong. Strength: %d/100", strength);
    }
    else {
        printf("Password is very strong. Strength: %d/100", strength);
    }
}

int main() {
    char password[100];
    printf("Enter the password: ");
    scanf("%s", password);
    
    printStrength(password);
    return 0;
}