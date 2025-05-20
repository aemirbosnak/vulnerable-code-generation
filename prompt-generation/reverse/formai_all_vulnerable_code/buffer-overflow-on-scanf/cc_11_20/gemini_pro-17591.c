//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>

// Structure to store password information
typedef struct password {
    char value[101];
    int strength;
} Password;

// Function to check password strength
int check_password_strength(Password *password) {
    int score = 0;

    // Check password length
    if (strlen(password->value) < 8) {
        score -= 10;
    } else if (strlen(password->value) < 12) {
        score -= 5;
    }

    // Check for uppercase letters
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password->value); i++) {
        if (password->value[i] >= 'A' && password->value[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        score -= 5;
    }

    // Check for lowercase letters
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password->value); i++) {
        if (password->value[i] >= 'a' && password->value[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        score -= 5;
    }

    // Check for digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password->value); i++) {
        if (password->value[i] >= '0' && password->value[i] <= '9') {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        score -= 5;
    }

    // Check for special characters
    int has_special_char = 0;
    for (int i = 0; i < strlen(password->value); i++) {
        if (!((password->value[i] >= 'a' && password->value[i] <= 'z') ||
              (password->value[i] >= 'A' && password->value[i] <= 'Z') ||
              (password->value[i] >= '0' && password->value[i] <= '9'))) {
            has_special_char = 1;
            break;
        }
    }
    if (!has_special_char) {
        score -= 5;
    }

    // Check for repeated characters
    int has_repeated_char = 0;
    for (int i = 0; i < strlen(password->value); i++) {
        for (int j = i + 1; j < strlen(password->value); j++) {
            if (password->value[i] == password->value[j]) {
                has_repeated_char = 1;
                break;
            }
        }
    }
    if (has_repeated_char) {
        score -= 5;
    }

    // Set password strength based on score
    if (score >= 20) {
        password->strength = 10;
    } else if (score >= 10) {
        password->strength = 5;
    } else {
        password->strength = 0;
    }

    return score;
}

int main() {
    Password password;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password.value);

    // Check password strength
    int score = check_password_strength(&password);

    // Display password strength
    printf("Password strength: %d\n", password.strength);

    return 0;
}