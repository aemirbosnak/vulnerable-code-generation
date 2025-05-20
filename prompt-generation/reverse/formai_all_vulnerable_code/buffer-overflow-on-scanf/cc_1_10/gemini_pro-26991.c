//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Checks if the password contains at least one uppercase letter.
int hasUppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

// Checks if the password contains at least one lowercase letter.
int hasLowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

// Checks if the password contains at least one digit.
int hasDigit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

// Checks if the password contains at least one special character.
int hasSpecialCharacter(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            return 1;
        }
    }
    return 0;
}

// Checks if the password is strong enough.
int isStrongPassword(char *password) {
    if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH) {
        return 0;
    }
    if (!hasUppercase(password)) {
        return 0;
    }
    if (!hasLowercase(password)) {
        return 0;
    }
    if (!hasDigit(password)) {
        return 0;
    }
    if (!hasSpecialCharacter(password)) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isStrongPassword(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak. Please try again.\n");
    }

    return 0;
}