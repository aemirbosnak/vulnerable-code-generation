//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int strength = 0;
    int has_digits = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_special = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check for length
    int password_length = strlen(password);
    if (password_length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for digits
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            has_digits = 1;
            break;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Calculate password strength
    if (password_length >= 16) {
        strength++;
    }
    if (has_digits) {
        strength++;
    }
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_special) {
        strength++;
    }

    printf("Password strength: ");
    if (strength < 2) {
        printf("Weak\n");
    } else if (strength < 4) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}