//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if password contains uppercase letters
bool hasUppercase(char* password) {
    int i = 0;
    while (i < strlen(password)) {
        if (isupper(password[i])) {
            return true;
        }
        i++;
    }
    return false;
}

// Function to check if password contains lowercase letters
bool hasLowercase(char* password) {
    int i = 0;
    while (i < strlen(password)) {
        if (islower(password[i])) {
            return true;
        }
        i++;
    }
    return false;
}

// Function to check if password contains digits
bool hasDigits(char* password) {
    int i = 0;
    while (i < strlen(password)) {
        if (isdigit(password[i])) {
            return true;
        }
        i++;
    }
    return false;
}

// Function to check if password contains special characters
bool hasSpecial(char* password) {
    char specialChars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int i = 0;
    while (i < strlen(password)) {
        if (strchr(specialChars, password[i])!= NULL) {
            return true;
        }
        i++;
    }
    return false;
}

// Function to check password strength
void checkPasswordStrength(char* password) {
    printf("Password Strength: ");
    if (hasUppercase(password)) {
        printf("Uppercase letters present. ");
    }
    if (hasLowercase(password)) {
        printf("Lowercase letters present. ");
    }
    if (hasDigits(password)) {
        printf("Digits present. ");
    }
    if (hasSpecial(password)) {
        printf("Special characters present. ");
    }
    if (strlen(password) >= 8) {
        printf("Password is at least 8 characters long. ");
    }
    if (hasUppercase(password) && hasLowercase(password) && hasDigits(password) && hasSpecial(password) && strlen(password) >= 8) {
        printf("Password is strong. ");
    }
    printf("\n");
}

// Main function
int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    checkPasswordStrength(password);
    return 0;
}