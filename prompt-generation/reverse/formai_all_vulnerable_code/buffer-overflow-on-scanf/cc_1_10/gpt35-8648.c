//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8

// Function to check if a password contains at least one uppercase letter
int has_uppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a password contains at least one lowercase letter
int has_lowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a password contains at least one digit
int has_digit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a password contains at least one special character
int has_special_char(char* password) {
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
    for (int i = 0; i < strlen(password); i++) {
        for (int j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a password meets the minimum requirements for strength
int is_strong(char* password) {
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0;
    }
    if (!has_uppercase(password)) {
        return 0;
    }
    if (!has_lowercase(password)) {
        return 0;
    }
    if (!has_digit(password)) {
        return 0;
    }
    if (!has_special_char(password)) {
        return 0;
    }
    return 1;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_strong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak. Please choose a stronger password.\n");
    }

    return 0;
}