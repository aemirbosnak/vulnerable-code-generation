//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int is_valid_password(char* password) {
    // Check if the password is too short
    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for repeated characters
    int repeated_chars = 0;
    char prev_char = password[0];
    for (int i = 1; i < strlen(password); i++) {
        if (password[i] == prev_char) {
            repeated_chars++;
        }
        prev_char = password[i];
    }
    if (repeated_chars > 0) {
        printf("Password must not contain repeated characters.\n");
        return 0;
    }

    // Check for common words
    int is_common_word = 0;
    char* common_words[] = {"password", "admin", "123456", "qwerty", "letmein", "welcome", "monkey", "dragon", "sunshine", "iloveyou"};
    for (int i = 0; i < sizeof(common_words)/sizeof(common_words[0]); i++) {
        if (strcmp(password, common_words[i]) == 0) {
            is_common_word = 1;
            break;
        }
    }
    if (is_common_word) {
        printf("Password must not contain common words.\n");
        return 0;
    }

    // Check for complexity
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special = 1;
        }
    }
    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
        return 0;
    }

    // Password is valid
    printf("Password is valid.\n");
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    is_valid_password(password);
    return 0;
}