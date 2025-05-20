//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

// password strength levels
enum strength {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
};

// check if a character is a digit
int is_digit(char c) {
    return isdigit(c) != 0;
}

// check if a character is an uppercase letter
int is_uppercase(char c) {
    return isupper(c) != 0;
}

// check if a character is a lowercase letter
int is_lowercase(char c) {
    return islower(c) != 0;
}

// check if a character is a special character
int is_special(char c) {
    return ispunct(c) != 0;
}

// check if a password meets minimum length requirements
int is_long_enough(char* password) {
    int len = strlen(password);
    return len >= MIN_PASSWORD_LENGTH && len <= MAX_PASSWORD_LENGTH;
}

// check password strength level
enum strength check_password_strength(char* password) {
    int len = strlen(password);
    int has_digit = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_special = 0;

    for (int i = 0; i < len; i++) {
        char c = password[i];

        if (is_digit(c)) {
            has_digit = 1;
        }
        else if (is_uppercase(c)) {
            has_uppercase = 1;
        }
        else if (is_lowercase(c)) {
            has_lowercase = 1;
        }
        else if (is_special(c)) {
            has_special = 1;
        }
    }

    if (has_digit && has_uppercase && has_lowercase && has_special) {
        return VERY_STRONG;
    }
    else if ((has_digit && has_uppercase && has_lowercase) ||
             (has_digit && has_uppercase && has_special) ||
             (has_digit && has_lowercase && has_special) ||
             (has_uppercase && has_lowercase && has_special)) {
        return STRONG;
    }
    else if ((has_digit && has_uppercase) ||
             (has_digit && has_lowercase) ||
             (has_digit && has_special) ||
             (has_uppercase && has_lowercase) ||
             (has_uppercase && has_special) ||
             (has_lowercase && has_special)) {
        return MEDIUM;
    }
    else {
        return WEAK;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    if (!is_long_enough(password)) {
        printf("Password is too short or too long. Please enter a password between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    enum strength password_strength = check_password_strength(password);
    switch (password_strength) {
        case WEAK:
            printf("Password strength: Weak\n");
            break;
        case MEDIUM:
            printf("Password strength: Medium\n");
            break;
        case STRONG:
            printf("Password strength: Strong\n");
            break;
        case VERY_STRONG:
            printf("Password strength: Very strong\n");
            break;
    }

    return 0;
}