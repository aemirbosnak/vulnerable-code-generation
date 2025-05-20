//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove trailing newline character
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    // Check password strength
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (isalnum(c)) {
            has_special_char = 1;
        }
    }

    int strength = 0;

    if (length >= 8) {
        strength++;
    }

    if (has_uppercase && has_lowercase) {
        strength++;
    }

    if (has_digit) {
        strength++;
    }

    if (has_special_char) {
        strength++;
    }

    if (strength == 0) {
        printf("Password is very weak.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else if (strength == 3) {
        printf("Password is strong.\n");
    } else {
        printf("Password is very strong.\n");
    }

    return 0;
}