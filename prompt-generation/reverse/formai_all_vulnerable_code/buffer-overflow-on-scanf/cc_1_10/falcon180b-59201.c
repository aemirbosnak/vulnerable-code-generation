//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PASSWORD_LENGTH 8

// Function to check if the password contains at least one uppercase letter
int contains_uppercase(char* password) {
    int i = 0;
    while (password[i]) {
        if (isupper(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int contains_lowercase(char* password) {
    int i = 0;
    while (password[i]) {
        if (islower(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check if the password contains at least one digit
int contains_digit(char* password) {
    int i = 0;
    while (password[i]) {
        if (isdigit(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check if the password contains at least one special character
int contains_special_char(char* password) {
    int i = 0;
    while (password[i]) {
        if (!isalnum(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check the strength of the password
int check_password_strength(char* password) {
    int strength = 0;
    if (contains_uppercase(password)) {
        strength++;
    }
    if (contains_lowercase(password)) {
        strength++;
    }
    if (contains_digit(password)) {
        strength++;
    }
    if (contains_special_char(password)) {
        strength++;
    }
    return strength;
}

int main() {
    char password[PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    if (strength == 0) {
        printf("Password is very weak.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else if (strength == 3) {
        printf("Password is strong.\n");
    } else if (strength == 4) {
        printf("Password is very strong.\n");
    }
    return 0;
}