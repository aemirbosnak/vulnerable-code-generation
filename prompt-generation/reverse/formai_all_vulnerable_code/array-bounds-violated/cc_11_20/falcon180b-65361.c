//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i;

    // Get password from user
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove newline character from password
    password[length - 1] = '\0';

    // Check password strength
    int is_lowercase = 0;
    int is_uppercase = 0;
    int is_digit = 0;
    int is_special = 0;

    for (i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                is_lowercase = 1;
            } else if (isupper(password[i])) {
                is_uppercase = 1;
            }
        } else if (isdigit(password[i])) {
            is_digit = 1;
        } else if (!isalnum(password[i])) {
            is_special = 1;
        }
    }

    // Print password strength
    if (length < 8) {
        printf("Weak\n");
    } else if (length >= 8 && length < 12) {
        if (is_lowercase && is_uppercase && is_digit) {
            printf("Medium\n");
        } else {
            printf("Weak\n");
        }
    } else if (length >= 12) {
        if (is_lowercase && is_uppercase && is_digit && is_special) {
            printf("Strong\n");
        } else {
            printf("Medium\n");
        }
    }

    return 0;
}