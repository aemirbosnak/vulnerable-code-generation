//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

// Password strength evaluation criteria
#define MIN_LENGTH 8
#define MAX_LENGTH 25
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

// Character class flags
#define UPPERCASE 1
#define LOWERCASE 2
#define DIGIT 4
#define SPECIAL 8

// Function to check password strength
int checkPasswordStrength(char* password) {
    // Check password length
    if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH) {
        return 0;
    }

    // Check for uppercase, lowercase, digit, and special characters
    int flags = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            flags |= UPPERCASE;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            flags |= LOWERCASE;
        } else if (password[i] >= '0' && password[i] <= '9') {
            flags |= DIGIT;
        } else {
            flags |= SPECIAL;
        }
    }

    // Check if all criteria are met
    if (flags & UPPERCASE && flags & LOWERCASE && flags & DIGIT && flags & SPECIAL) {
        return 1;
    }

    // Password is weak
    return 0;
}

// Main function
int main() {
    // Get password from user
    char password[MAX_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    int strength = checkPasswordStrength(password);

    // Print password strength
    if (strength) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak. Please try again.\n");
    }

    return 0;
}