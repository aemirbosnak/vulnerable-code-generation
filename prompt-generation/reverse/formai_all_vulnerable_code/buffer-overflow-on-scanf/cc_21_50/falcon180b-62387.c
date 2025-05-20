//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char password[100];
    int length;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check if password contains at least one uppercase letter
    bool has_uppercase = false;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = true;
            break;
        }
    }

    // Check if password contains at least one lowercase letter
    bool has_lowercase = false;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = true;
            break;
        }
    }

    // Check if password contains at least one digit
    bool has_digit = false;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = true;
            break;
        }
    }

    // Check if password contains at least one special character
    bool has_special_char = false;
    char special_chars[] = "!@#$%^&*()_+-=[]{}\\|;':\",./<>?";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                has_special_char = true;
                break;
            }
        }
        if (has_special_char) {
            break;
        }
    }

    // Check if password is at least 8 characters long
    bool is_long_enough = false;
    if (length >= 8) {
        is_long_enough = true;
    }

    // Print password strength
    if (has_uppercase && has_lowercase && has_digit && has_special_char && is_long_enough) {
        printf("Your password is very strong.\n");
    } else if (has_uppercase && has_lowercase && has_digit && is_long_enough) {
        printf("Your password is strong.\n");
    } else if (has_uppercase && has_lowercase && is_long_enough) {
        printf("Your password is moderate.\n");
    } else if (is_long_enough) {
        printf("Your password is weak.\n");
    } else {
        printf("Your password is very weak.\n");
    }

    return 0;
}