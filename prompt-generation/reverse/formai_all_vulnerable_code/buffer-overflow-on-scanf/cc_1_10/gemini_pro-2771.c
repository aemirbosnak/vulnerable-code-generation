//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length.
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length.
#define MAX_PASSWORD_LENGTH 64

// Define the character classes used in the password strength check.
#define CHAR_CLASS_LOWERCASE 0x01
#define CHAR_CLASS_UPPERCASE 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength levels.
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages.
const char *password_strength_messages[] = {
    "Weak",
    "Medium",
    "Strong"
};

// Check if the password is long enough.
int check_password_length(const char *password) {
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0;
    }
    return 1;
}

// Check if the password contains at least one lowercase character.
int check_password_lowercase(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one uppercase character.
int check_password_uppercase(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one digit.
int check_password_digit(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one symbol.
int check_password_symbol(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Check the password strength.
int check_password_strength(const char *password) {
    int strength = 0;

    if (check_password_length(password)) {
        strength++;
    }
    if (check_password_lowercase(password)) {
        strength++;
    }
    if (check_password_uppercase(password)) {
        strength++;
    }
    if (check_password_digit(password)) {
        strength++;
    }
    if (check_password_symbol(password)) {
        strength++;
    }

    return strength;
}

// Get the password strength message.
const char *get_password_strength_message(int strength) {
    return password_strength_messages[strength];
}

// Main function.
int main() {
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    printf("Password strength: %s\n", get_password_strength_message(strength));

    return 0;
}