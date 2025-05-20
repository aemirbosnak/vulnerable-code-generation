//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length, i;
    int uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_count = 0;

    // Prompt user to enter password
    printf("Enter your password: ");
    scanf("%s", password);

    // Get password length
    password_length = strlen(password);

    // Check for uppercase letters
    for (i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for digits
    for (i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    for (i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // Calculate password strength
    int strength = 0;
    if (password_length >= 8) {
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