//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
// Welcome to the Cyberpunk Password Strength Checker!
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character appears in a string
int char_in_string(char c, char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[100];
    printf("Enter Password: ");
    scanf("%s", password);

    int length = strlen(password);
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_special = 0;

    // Check for password length
    if (length < 8) {
        printf("Password is too short! Must be at least 8 characters\n");
        return 0;
    }

    // Check for lowercase, uppercase, digit, and special character
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lower = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else if (char_in_string(password[i], "!@#$%^&*()_+-=[]{}|;:,.<>?")) {
            has_special = 1;
        }
    }

    // Check overall password strength
    int strength = has_lower + has_upper + has_digit + has_special;
    if (strength <= 2) {
        printf("Weak password! Must contain at least 3 of the following: lowercase, uppercase, digit, special character\n");
    } else if (strength == 3) {
        printf("Medium password! Good job, but can be improved!\n");
    } else {
        printf("Strong password! You are Cyberpunk Certified!\n");
    }

    return 0;
}