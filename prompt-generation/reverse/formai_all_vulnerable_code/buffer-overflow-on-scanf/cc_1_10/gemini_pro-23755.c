//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Minimum length of password
#define MIN_LENGTH 8

// Maximum length of password
#define MAX_LENGTH 32

// Define the character classes
#define CHAR_CLASS_LOWER 0
#define CHAR_CLASS_UPPER 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the strength levels
#define STRENGTH_LEVEL_WEAK 0
#define STRENGTH_LEVEL_MEDIUM 1
#define STRENGTH_LEVEL_STRONG 2

// Function to check if a character is in a given character class
int is_in_char_class(char c, int char_class) {
    switch (char_class) {
        case CHAR_CLASS_LOWER:
            return (c >= 'a' && c <= 'z');
        case CHAR_CLASS_UPPER:
            return (c >= 'A' && c <= 'Z');
        case CHAR_CLASS_DIGIT:
            return (c >= '0' && c <= '9');
        case CHAR_CLASS_SPECIAL:
            return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%');
        default:
            return 0;
    }
}

// Function to calculate the strength of a password
int calculate_strength(char *password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) < MIN_LENGTH) {
        return STRENGTH_LEVEL_WEAK;
    } else if (strlen(password) > MAX_LENGTH) {
        return STRENGTH_LEVEL_WEAK;
    }

    // Check if the password contains all four character classes
    int char_classes[4] = {0, 0, 0, 0};
    for (int i = 0; i < strlen(password); i++) {
        for (int j = 0; j < 4; j++) {
            if (is_in_char_class(password[i], j)) {
                char_classes[j] = 1;
            }
        }
    }
    if (char_classes[CHAR_CLASS_LOWER] == 0 || char_classes[CHAR_CLASS_UPPER] == 0 || char_classes[CHAR_CLASS_DIGIT] == 0 || char_classes[CHAR_CLASS_SPECIAL] == 0) {
        return STRENGTH_LEVEL_WEAK;
    }

    // Check if the password contains any repeated characters
    for (int i = 0; i < strlen(password); i++) {
        for (int j = i + 1; j < strlen(password); j++) {
            if (password[i] == password[j]) {
                return STRENGTH_LEVEL_WEAK;
            }
        }
    }

    // If the password meets all the criteria, then it is strong
    return STRENGTH_LEVEL_STRONG;
}

// Function to display the strength of a password
void display_strength(char *password) {
    int strength = calculate_strength(password);

    switch (strength) {
        case STRENGTH_LEVEL_WEAK:
            printf("Password is weak\n");
            break;
        case STRENGTH_LEVEL_MEDIUM:
            printf("Password is medium\n");
            break;
        case STRENGTH_LEVEL_STRONG:
            printf("Password is strong\n");
            break;
        default:
            printf("Invalid password\n");
    }
}

// Main function
int main() {
    char password[MAX_LENGTH + 1];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Display the strength of the password
    display_strength(password);

    return 0;
}