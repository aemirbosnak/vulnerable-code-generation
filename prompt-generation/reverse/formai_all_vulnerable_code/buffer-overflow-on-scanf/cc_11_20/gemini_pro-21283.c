//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <string.h>

// Password strength criteria
#define MIN_LENGTH 8
#define MAX_LENGTH 64
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

// Password strength levels
enum Strength {
    WEAK,
    OK,
    STRONG,
    VERY_STRONG
};

// Function to check password strength
enum Strength check_password_strength(const char *password) {
    int length = strlen(password);

    // Check password length
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return WEAK;
    }

    // Check for uppercase characters
    int uppercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase_count++;
        }
    }
    if (uppercase_count < MIN_UPPERCASE) {
        return WEAK;
    }

    // Check for lowercase characters
    int lowercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase_count++;
        }
    }
    if (lowercase_count < MIN_LOWERCASE) {
        return WEAK;
    }

    // Check for digits
    int digit_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        }
    }
    if (digit_count < MIN_DIGIT) {
        return WEAK;
    }

    // Check for special characters
    int special_count = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }
    if (special_count < MIN_SPECIAL) {
        return WEAK;
    }

    // Check if password is strong enough
    if (uppercase_count >= MIN_UPPERCASE && lowercase_count >= MIN_LOWERCASE && digit_count >= MIN_DIGIT && special_count >= MIN_SPECIAL) {
        return VERY_STRONG;
    } else if (uppercase_count >= MIN_UPPERCASE / 2 && lowercase_count >= MIN_LOWERCASE / 2 && digit_count >= MIN_DIGIT / 2 && special_count >= MIN_SPECIAL / 2) {
        return STRONG;
    } else if (uppercase_count >= MIN_UPPERCASE / 4 && lowercase_count >= MIN_LOWERCASE / 4 && digit_count >= MIN_DIGIT / 4 && special_count >= MIN_SPECIAL / 4) {
        return OK;
    } else {
        return WEAK;
    }
}

// Main function
int main() {
    // Get password from user
    char password[MAX_LENGTH + 1];
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    enum Strength strength = check_password_strength(password);

    // Print password strength
    switch (strength) {
    case WEAK:
        printf("Password is weak.\n");
        break;
    case OK:
        printf("Password is okay.\n");
        break;
    case STRONG:
        printf("Password is strong.\n");
        break;
    case VERY_STRONG:
        printf("Password is very strong.\n");
        break;
    }

    return 0;
}