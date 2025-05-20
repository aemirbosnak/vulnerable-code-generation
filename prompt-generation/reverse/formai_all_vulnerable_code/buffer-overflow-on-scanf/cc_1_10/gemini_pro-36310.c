//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum and maximum password lengths
#define MIN_LENGTH 8
#define MAX_LENGTH 256

// Define the character classes
#define CHAR_CLASS_LOWER 0x01
#define CHAR_CLASS_UPPER 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Define the error codes
#define ERROR_NONE 0
#define ERROR_TOO_SHORT 1
#define ERROR_TOO_LONG 2
#define ERROR_NO_LOWER 3
#define ERROR_NO_UPPER 4
#define ERROR_NO_DIGIT 5
#define ERROR_NO_SYMBOL 6

// Define the error messages
const char *error_messages[] = {
    "No error",
    "Password is too short",
    "Password is too long",
    "Password does not contain any lowercase characters",
    "Password does not contain any uppercase characters",
    "Password does not contain any digits",
    "Password does not contain any symbols"
};

// Check the password strength
int check_password_strength(const char *password) {
    // Check the password length
    if (strlen(password) < MIN_LENGTH) {
        return ERROR_TOO_SHORT;
    }
    if (strlen(password) > MAX_LENGTH) {
        return ERROR_TOO_LONG;
    }

    // Check the password character classes
    int char_classes = 0;
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            char_classes |= CHAR_CLASS_LOWER;
        } else if (c >= 'A' && c <= 'Z') {
            char_classes |= CHAR_CLASS_UPPER;
        } else if (c >= '0' && c <= '9') {
            char_classes |= CHAR_CLASS_DIGIT;
        } else {
            char_classes |= CHAR_CLASS_SYMBOL;
        }
    }

    // Check if all character classes are present
    if ((char_classes & CHAR_CLASS_LOWER) == 0) {
        return ERROR_NO_LOWER;
    }
    if ((char_classes & CHAR_CLASS_UPPER) == 0) {
        return ERROR_NO_UPPER;
    }
    if ((char_classes & CHAR_CLASS_DIGIT) == 0) {
        return ERROR_NO_DIGIT;
    }
    if ((char_classes & CHAR_CLASS_SYMBOL) == 0) {
        return ERROR_NO_SYMBOL;
    }

    // Password is strong
    return STRENGTH_STRONG;
}

// Print the password strength
void print_password_strength(int strength) {
    switch (strength) {
        case STRENGTH_WEAK:
            printf("Weak\n");
            break;
        case STRENGTH_MEDIUM:
            printf("Medium\n");
            break;
        case STRENGTH_STRONG:
            printf("Strong\n");
            break;
    }
}

int main() {
    // Get the password from the user
    char password[MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the password strength
    int strength = check_password_strength(password);

    // Print the password strength
    printf("Password strength: ");
    print_password_strength(strength);

    return 0;
}