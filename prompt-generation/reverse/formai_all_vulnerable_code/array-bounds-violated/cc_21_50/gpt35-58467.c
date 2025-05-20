//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {

    int uppercase = 0, lowercase = 0, digits = 0, special = 0, repeat = 0;
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from fgets
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    // Check password length
    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long\n");
        return 1;
    }

    // Check for uppercase, lowercase, digits, and special characters
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        }
        if (islower(password[i])) {
            lowercase = 1;
        }
        if (isdigit(password[i])) {
            digits = 1;
        }
        if (!isalnum(password[i])) {
            special = 1;
        }
    }

    // Check for repeating characters
    for (int i = 0; i < strlen(password); i++) {
        for (int j = i + 1; j < strlen(password); j++) {
            if (password[i] == password[j]) {
                repeat = 1;
            }
        }
    }

    // Check password strength
    if (uppercase && lowercase && digits && special && !repeat) {
        printf("Password is very strong and almost unbreakable!\n");
        return 0;
    }
    else if (uppercase && lowercase && digits && special) {
        printf("Password is strong\n");
        return 0;
    }
    else if ((uppercase || lowercase) && digits && special) {
        printf("Password is moderate\n");
        return 0;
    }
    else {
        printf("Password is weak\n");
        return 1;
    }
}