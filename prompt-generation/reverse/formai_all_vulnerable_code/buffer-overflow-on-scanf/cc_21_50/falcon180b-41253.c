//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int score = 0;
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    bool has_special_char = false;

    // Get password input from user
    printf("Enter password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check if password contains uppercase letters
    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            has_uppercase = true;
            break;
        }
    }

    // Check if password contains lowercase letters
    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            has_lowercase = true;
            break;
        }
    }

    // Check if password contains digits
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            has_digit = true;
            break;
        }
    }

    // Check if password contains special characters
    for (int i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = true;
            break;
        }
    }

    // Calculate password strength score
    if (password_length < 8) {
        printf("Weak password\n");
        return 0;
    }
    if (password_length >= 8 && password_length < 12) {
        if (has_uppercase && has_lowercase && has_digit) {
            printf("Moderate password\n");
            score = 3;
        } else {
            printf("Weak password\n");
            score = 2;
        }
    } else if (password_length >= 12) {
        if (has_uppercase && has_lowercase && has_digit && has_special_char) {
            printf("Strong password\n");
            score = 4;
        } else if (has_uppercase && has_lowercase && has_digit) {
            printf("Moderate password\n");
            score = 3;
        } else if (has_uppercase && has_lowercase) {
            printf("Weak password\n");
            score = 2;
        } else {
            printf("Very weak password\n");
            score = 1;
        }
    }

    return score;
}