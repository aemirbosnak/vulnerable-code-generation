//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    printf("Enter password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for uppercase letters
    if (isupper(password[0])) {
        has_uppercase = 1;
    }

    // Check for lowercase letters
    if (islower(password[0])) {
        has_lowercase = 1;
    }

    // Check for digits
    if (isdigit(password[0])) {
        has_digit = 1;
    }

    // Check for special characters
    if (strpbrk(password, "!@#$%^&*()_+-=[]{}|;:,.<>/?")!= NULL) {
        has_special_char = 1;
    }

    // Calculate password strength
    int strength = 0;
    if (password_length >= 8) {
        strength++;
    }
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_digit) {
        strength++;
    }
    if (has_special_char) {
        strength++;
    }

    // Print password strength
    printf("Password strength: ");
    if (strength == 0) {
        printf("Very weak\n");
    } else if (strength == 1) {
        printf("Weak\n");
    } else if (strength == 2) {
        printf("Moderate\n");
    } else if (strength == 3) {
        printf("Strong\n");
    } else if (strength == 4) {
        printf("Very strong\n");
    }

    return 0;
}