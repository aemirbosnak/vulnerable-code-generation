//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from password
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    // Check password length
    if (length < 8) {
        printf("Password is too short. It should be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // Calculate password strength
    int strength = 0;
    if (length >= 12) {
        strength++;
    }
    if (uppercase_count > 0) {
        strength++;
    }
    if (lowercase_count > 0) {
        strength++;
    }
    if (digit_count > 0) {
        strength++;
    }
    if (special_count > 0) {
        strength++;
    }

    // Print password strength
    printf("\nYour password strength is: ");
    if (strength == 0) {
        printf("Weak\n");
    } else if (strength == 1) {
        printf("Fair\n");
    } else if (strength == 2) {
        printf("Good\n");
    } else if (strength == 3) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}