//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Define the password strength levels
enum PasswordStrength {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
};

// Define the minimum length of a password
#define MIN_PASSWORD_LENGTH 8

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 64

// Define the character classes used in the password strength check
enum CharacterClass {
    LOWER,
    UPPER,
    DIGIT,
    SYMBOL
};

// Define the number of character classes used in the password strength check
#define NUM_CHARACTER_CLASSES 4

// Define the minimum number of character classes required for a strong password
#define MIN_CHARACTER_CLASSES_FOR_STRONG_PASSWORD 3

// Define the minimum number of character classes required for a very strong password
#define MIN_CHARACTER_CLASSES_FOR_VERY_STRONG_PASSWORD 4

// Define the weight of each character class in the password strength check
int character_class_weights[NUM_CHARACTER_CLASSES] = {1, 2, 3, 4};

// Define the password strength calculation function
enum PasswordStrength calculate_password_strength(const char *password) {
    // Check if the password is empty
    if (strlen(password) == 0) {
        return WEAK;
    }

    // Check if the password is too short
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return WEAK;
    }

    // Check if the password is too long
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return WEAK;
    }

    // Initialize the character class counts
    int character_class_counts[NUM_CHARACTER_CLASSES] = {0, 0, 0, 0};

    // Iterate over the password and count the number of characters in each character class
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            character_class_counts[LOWER]++;
        } else if (c >= 'A' && c <= 'Z') {
            character_class_counts[UPPER]++;
        } else if (c >= '0' && c <= '9') {
            character_class_counts[DIGIT]++;
        } else {
            character_class_counts[SYMBOL]++;
        }
    }

    // Calculate the password strength score
    int password_strength_score = 0;
    for (int i = 0; i < NUM_CHARACTER_CLASSES; i++) {
        password_strength_score += character_class_counts[i] * character_class_weights[i];
    }

    // Determine the password strength level
    if (password_strength_score < 10) {
        return WEAK;
    } else if (password_strength_score < 20) {
        return MEDIUM;
    } else if (password_strength_score < 30) {
        return STRONG;
    } else {
        return VERY_STRONG;
    }
}

// Define the main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password strength
    enum PasswordStrength password_strength = calculate_password_strength(password);

    // Print the password strength
    switch (password_strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MEDIUM:
            printf("Your password is medium strength.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}