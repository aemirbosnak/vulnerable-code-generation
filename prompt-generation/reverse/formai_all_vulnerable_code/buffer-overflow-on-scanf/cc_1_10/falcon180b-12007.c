//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to check if string is a palindrome
bool isPalindrome(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(str[i]!= str[len-i-1]) {
            return false;
        }
    }
    return true;
}

// Function to check if string contains only alphabets
bool isAlphabetic(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to check if string contains at least one uppercase letter
bool hasUppercase(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(isupper(str[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if string contains at least one lowercase letter
bool hasLowercase(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(islower(str[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if string contains at least one digit
bool hasDigit(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if string contains at least one special character
bool hasSpecialChar(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(!isalnum(str[i])) {
            return true;
        }
    }
    return false;
}

// Function to check password strength
void checkPasswordStrength(char* password) {
    int length = strlen(password);
    if(length < 8) {
        printf("Weak: Password should be at least 8 characters long.\n");
    }
    else if(length >= 8 && length < 12) {
        printf("Average: Password should be at least 12 characters long.\n");
    }
    else if(length >= 12 && length < 16) {
        printf("Strong: Password is reasonably strong.\n");
    }
    else if(length >= 16) {
        printf("Very Strong: Password is very strong.\n");
    }
    if(isPalindrome(password)) {
        printf("Password is a palindrome.\n");
    }
    if(!isAlphabetic(password)) {
        printf("Password should contain only alphabets.\n");
    }
    if(!hasUppercase(password)) {
        printf("Password should contain at least one uppercase letter.\n");
    }
    if(!hasLowercase(password)) {
        printf("Password should contain at least one lowercase letter.\n");
    }
    if(!hasDigit(password)) {
        printf("Password should contain at least one digit.\n");
    }
    if(!hasSpecialChar(password)) {
        printf("Password should contain at least one special character.\n");
    }
}

int main() {
    char password[100];
    printf("Enter Password: ");
    scanf("%s", password);
    checkPasswordStrength(password);
    return 0;
}