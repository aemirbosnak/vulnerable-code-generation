//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 30

/* Function to check password strength */
int check_password_strength(char* password) {
    int length = strlen(password);
    int has_uppercase = 0, has_lowercase = 0, has_number = 0;
    int has_special_char = 0;
    int consecutive_chars = 0;

    /* Check for minimum length */
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    /* Check for uppercase letters */
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    /* Check for lowercase letters */
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    /* Check for numbers */
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    /* Check for special characters */
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    /* Check for consecutive characters */
    for (int i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            consecutive_chars++;
        }
    }

    /* Determine password strength */
    if (length <= 8) {
        printf("Password is weak.\n");
    } else if (has_uppercase && has_lowercase && has_number && has_special_char && consecutive_chars <= 2) {
        printf("Password is strong.\n");
    } else if (has_uppercase && has_lowercase && has_number && has_special_char && consecutive_chars > 2) {
        printf("Password is medium.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH] = {0};

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}