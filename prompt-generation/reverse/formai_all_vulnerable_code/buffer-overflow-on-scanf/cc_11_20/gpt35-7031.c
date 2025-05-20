//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define PASSWORD_LENGTH 10 // minimum password length
#define SPECIAL_CHARS "!@#$%^&*" // special characters

int main() {
    char password[100];
    int length, has_uppercase, has_lowercase, has_number, has_special_char, strength = 0, i;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check if password meets minimum length requirement
    if (length < PASSWORD_LENGTH) {
        strength--;
        printf("Password must be at least %d characters long.\n", PASSWORD_LENGTH);
    } else {
        strength++;
    }

    // Check if password contains uppercase, lowercase, numbers, and special characters
    has_uppercase = has_lowercase = has_number = has_special_char = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        if (islower(password[i])) {
            has_lowercase = 1;
        }
        if (isdigit(password[i])) {
            has_number = 1;
        }
        if (strchr(SPECIAL_CHARS, password[i])) {
            has_special_char = 1;
        }
    }

    if (!has_uppercase) {
        strength--;
        printf("Password must contain at least one uppercase letter.\n");
    } else {
        strength++;
    }

    if (!has_lowercase) {
        strength--;
        printf("Password must contain at least one lowercase letter.\n");
    } else {
        strength++;
    }

    if (!has_number) {
        strength--;
        printf("Password must contain at least one number.\n");
    } else {
        strength++;
    }

    if (!has_special_char) {
        strength--;
        printf("Password must contain at least one special character (%s).\n", SPECIAL_CHARS);
    } else {
        strength++;
    }

    // Provide feedback on password strength
    if (strength >= 3) {
        printf("Your password is strong! Congratulations!\n");
    } else if (strength == 2) {
        printf("Your password is moderately strong.\n");
    } else if (strength == 1) {
        printf("Your password is weak. Consider making it stronger.\n");
    } else {
        printf("Your password is very weak. Please choose a stronger password.\n");
    }

    return 0;
}