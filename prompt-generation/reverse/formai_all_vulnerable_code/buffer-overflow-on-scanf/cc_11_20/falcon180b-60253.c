//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int lowercase_count = 0;
    int uppercase_count = 0;
    int numeric_count = 0;
    int special_count = 0;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    password_length = strlen(password);
    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password must be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for numeric characters
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            numeric_count++;
        }
    }

    // Check for special characters
    for (int i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // Calculate password strength
    int strength = 0;
    if (password_length >= 12) {
        strength++;
    }
    if (lowercase_count > 0) {
        strength++;
    }
    if (uppercase_count > 0) {
        strength++;
    }
    if (numeric_count > 0) {
        strength++;
    }
    if (special_count > 0) {
        strength++;
    }

    // Print password strength
    printf("Password strength: ");
    if (strength == 0) {
        printf("Very Weak\n");
    } else if (strength == 1) {
        printf("Weak\n");
    } else if (strength == 2) {
        printf("Moderate\n");
    } else if (strength == 3) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}