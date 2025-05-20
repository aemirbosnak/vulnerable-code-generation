//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length = 0;

    // Get password from user
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    length = strlen(password);

    // Remove newline character from password
    password[length - 1] = '\0';

    // Check password strength
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;
    int has_consecutive_characters = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (!isalnum(password[i])) {
            has_special_character = 1;
        } else if (i > 0 && islower(password[i]) && islower(password[i - 1])) {
            has_consecutive_characters = 1;
        }
    }

    // Print password strength
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_number) {
        strength++;
    }
    if (has_special_character) {
        strength++;
    }
    if (!has_consecutive_characters) {
        strength++;
    }

    if (strength == 0) {
        printf("Weak\n");
    } else if (strength == 1) {
        printf("Medium\n");
    } else if (strength == 2) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}