//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

int is_password_strong(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    // Check for minimum length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for number
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check for password strength
    if (has_uppercase && has_lowercase && has_number && has_special_char) {
        printf("Password is strong.\n");
        return 1;
    } else {
        printf("Password is weak.\n");
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    int result = is_password_strong(password);

    if (result == 1) {
        printf("Password strength: Strong\n");
    } else {
        printf("Password strength: Weak\n");
    }

    return 0;
}