//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: retro
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 10

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 20

// Define the character classes
#define CHAR_CLASS_LOWERCASE 0x01
#define CHAR_CLASS_UPPERCASE 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages
const char *password_strength_messages[] = {
    "Weak",
    "Medium",
    "Strong"
};

// Check if the password is long enough
int is_password_long_enough(const char *password) {
    return strlen(password) >= MIN_PASSWORD_LENGTH;
}

// Check if the password contains at least one lowercase character
int contains_lowercase_character(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one uppercase character
int contains_uppercase_character(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one digit
int contains_digit(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one symbol
int contains_symbol(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Calculate the password strength
int calculate_password_strength(const char *password) {
    int strength = 0;

    if (is_password_long_enough(password)) {
        strength++;
    }

    if (contains_lowercase_character(password)) {
        strength++;
    }

    if (contains_uppercase_character(password)) {
        strength++;
    }

    if (contains_digit(password)) {
        strength++;
    }

    if (contains_symbol(password)) {
        strength++;
    }

    return strength;
}

// Print the password strength message
void print_password_strength_message(int strength) {
    printf("Your password strength is: %s\n", password_strength_messages[strength]);
}

// Get the password from the user
char *get_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);

    printf("Please enter your password: ");
    scanf("%s", password);

    return password;
}

// Main function
int main() {
    char *password = get_password();

    int strength = calculate_password_strength(password);

    print_password_strength_message(strength);

    return 0;
}