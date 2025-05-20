//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password contains lowercase characters or not
int containsLowerCase(char password[]) {
    for(int i=0; i<strlen(password); i++) {
        if(islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains uppercase characters or not
int containsUpperCase(char password[]) {
    for(int i=0; i<strlen(password); i++) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains digits or not
int containsDigits(char password[]) {
    for(int i=0; i<strlen(password); i++) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains special characters or not
int containsSpecial(char password[]) {
    for(int i=0; i<strlen(password); i++) {
        if(!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    char password[100];
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int score = 0;

    // Check the length of the password
    if(length < 8) {
        printf("Your password is too short.\n");
        printf("Please enter a password that is at least 8 characters long.\n");
        return 1;
    }
    else if(length >= 8 && length <= 12) {
        score += 5;
    }
    else {
        score += 10;
    }

    // Check if the password contains lowercase characters
    if(containsLowerCase(password)) {
        score += 2;
    }
    else {
        printf("Your password does not contain any lowercase characters.\n");
    }

    // Check if the password contains uppercase characters
    if(containsUpperCase(password)) {
        score += 2;
    }
    else {
        printf("Your password does not contain any uppercase characters.\n");
    }

    // Check if the password contains digits
    if(containsDigits(password)) {
        score += 2;
    }
    else {
        printf("Your password does not contain any digits.\n");
    }

    // Check if the password contains special characters
    if(containsSpecial(password)) {
        score += 2;
    }
    else {
        printf("Your password does not contain any special characters.\n");
    }

    // Print the password strength score
    printf("Your password strength score is %d.\n", score);

    if(score <= 5) {
        printf("Your password is very weak.\n");
    }
    else if(score > 5 && score <= 10) {
        printf("Your password is weak.\n");
    }
    else if(score > 10 && score <= 15) {
        printf("Your password is strong.\n");
    }
    else {
        printf("Your password is very strong.\n");
    }

    return 0;
}