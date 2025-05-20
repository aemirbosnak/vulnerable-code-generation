//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 50

// Function to check if the password contains at least one uppercase letter
bool hasUppercase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one lowercase letter
bool hasLowercase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one digit
bool hasDigit(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one special character
bool hasSpecialChar(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check the strength of the password
int checkPasswordStrength(const char* password) {
    int strength = 0;
    if (hasUppercase(password)) {
        strength++;
    }
    if (hasLowercase(password)) {
        strength++;
    }
    if (hasDigit(password)) {
        strength++;
    }
    if (hasSpecialChar(password)) {
        strength++;
    }
    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    int strength = checkPasswordStrength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}