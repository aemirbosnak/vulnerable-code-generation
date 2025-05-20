//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool hasUpper(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if('A' <= password[i] && password[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

bool hasLower(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if('a' <= password[i] && password[i] <= 'z') {
            return true;
        }
    }
    return false;
}

bool hasNumber(const char* password) {
    for(int i = 0; password[i] != '\0'; i++) {
        if('0' <= password[i] && password[i] <= '9') {
            return true;
        }
    }
    return false;
}


int main() {
    printf("Welcome to Password Strength Checker\n");
    printf("Please enter your password: \n");

    char password[100];

    // Prompt the user for input and read it
    fgets(password, 100, stdin);
    password[strlen(password) - 1] = '\0'; // Remove trailing newline

    // Check password strength
    bool hasUpperChar = hasUpper(password);
    bool hasLowerChar = hasLower(password);
    bool hasNumberChar = hasNumber(password);
    int length = strlen(password);
    const char* strength = ""; // Initialize to empty string

    if(length < 8) {
        strength = "very weak";
    } else if(length < 12) {
        if(hasLowerChar && hasNumberChar) {
            strength = "medium";
        } else if(hasUpperChar && hasLowerChar) {
            strength = "medium";
        } else {
            strength = "weak";
        }
    } else {
        if(hasUpperChar && hasLowerChar && hasNumberChar) {
            strength = "strong";
        } else {
            strength = "medium";
        }
    }

    printf("The strength of your password is %s.\n", strength);

    return 0;
}