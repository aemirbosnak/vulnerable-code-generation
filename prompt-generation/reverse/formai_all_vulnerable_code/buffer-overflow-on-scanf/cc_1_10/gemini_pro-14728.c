//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password strength scoring system
#define MIN_SCORE 0
#define WEAK_SCORE 10
#define MEDIUM_SCORE 20
#define STRONG_SCORE 30

// Password rules
#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define MIN_NUMBERS 1
#define MIN_SYMBOLS 1

// Password strength messages
char *messages[] = {
    "Your password is too weak.",
    "Your password is weak.",
    "Your password is medium.",
    "Your password is strong."
};

// Function to check password strength
int check_password_strength(char *password) {
    int score = 0;

    // Check password length
    if (strlen(password) < MIN_LENGTH) {
        return MIN_SCORE;
    }

    // Check password for numbers
    int num_count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_count++;
        }
    }
    if (num_count < MIN_NUMBERS) {
        return WEAK_SCORE;
    }

    // Check password for symbols
    int symbol_count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= '0' && password[i] <= '9')) {
            symbol_count++;
        }
    }
    if (symbol_count < MIN_SYMBOLS) {
        return MEDIUM_SCORE;
    }

    // Password passed all checks
    return STRONG_SCORE;
}

// Main function
int main() {
    // Get password from user
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    int score = check_password_strength(password);

    // Print password strength message
    printf("%s\n", messages[score]);

    return 0;
}