//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits_only(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only lowercase letters
int is_lowercase_letters_only(char *str) {
    while (*str) {
        if (*str < 'a' || *str > 'z') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only uppercase letters
int is_uppercase_letters_only(char *str) {
    while (*str) {
        if (*str < 'A' || *str > 'Z') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only symbols
int is_symbols_only(char *str) {
    while (*str) {
        if (*str < '!' || *str > '~') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains at least one digit
int has_at_least_one_digit(char *str) {
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            return 1;
        }
        str++;
    }
    return 0;
}

// Function to check if a string contains at least one lowercase letter
int has_at_least_one_lowercase_letter(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            return 1;
        }
        str++;
    }
    return 0;
}

// Function to check if a string contains at least one uppercase letter
int has_at_least_one_uppercase_letter(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            return 1;
        }
        str++;
    }
    return 0;
}

// Function to check if a string contains at least one symbol
int has_at_least_one_symbol(char *str) {
    while (*str) {
        if (*str < '!' || *str > '~') {
            return 1;
        }
        str++;
    }
    return 0;
}

// Function to calculate the entropy of a string
double calculate_entropy(char *str) {
    int len = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    double entropy = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / len;
            entropy -= p * log2(p);
        }
    }
    return entropy;
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int score = 0;
    // Check if the password is empty
    if (strlen(password) == 0) {
        return 0;
    }
    // Check if the password contains only digits
    if (is_digits_only(password)) {
        return 1;
    }
    // Check if the password contains only lowercase letters
    if (is_lowercase_letters_only(password)) {
        return 2;
    }
    // Check if the password contains only uppercase letters
    if (is_uppercase_letters_only(password)) {
        return 3;
    }
    // Check if the password contains only symbols
    if (is_symbols_only(password)) {
        return 4;
    }
    // Check if the password contains at least one digit
    if (has_at_least_one_digit(password)) {
        score++;
    }
    // Check if the password contains at least one lowercase letter
    if (has_at_least_one_lowercase_letter(password)) {
        score++;
    }
    // Check if the password contains at least one uppercase letter
    if (has_at_least_one_uppercase_letter(password)) {
        score++;
    }
    // Check if the password contains at least one symbol
    if (has_at_least_one_symbol(password)) {
        score++;
    }
    // Calculate the entropy of the password
    double entropy = calculate_entropy(password);
    // Check if the password is strong
    if (score >= 4 && entropy >= 4) {
        return 5;
    }
    // Check if the password is medium
    if (score >= 3 && entropy >= 3) {
        return 4;
    }
    // Check if the password is weak
    if (score >= 2 && entropy >= 2) {
        return 3;
    }
    // Check if the password is very weak
    if (score >= 1 && entropy >= 1) {
        return 2;
    }
    // The password is invalid
    return 1;
}

int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    // Check the strength of the password
    int strength = check_password_strength(password);
    // Print the strength of the password
    printf("Your password strength is: %d\n", strength);
    return 0;
}