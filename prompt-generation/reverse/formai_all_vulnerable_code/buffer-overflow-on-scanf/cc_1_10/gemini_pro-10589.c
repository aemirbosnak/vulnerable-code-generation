//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Function to check if the password is long enough
int checkLength(char* password) {
    if (strlen(password) < MIN_LENGTH) {
        return 0;
    } else if (strlen(password) > MAX_LENGTH) {
        return 0;
    } else {
        return 1;
    }
}

// Function to check if the password contains at least one uppercase letter
int checkUppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int checkLowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one digit
int checkDigit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one special character
int checkSpecial(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password is strong
int checkStrong(char* password) {
    if (checkLength(password) && checkUppercase(password) && checkLowercase(password) && checkDigit(password) && checkSpecial(password)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (checkStrong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is not strong. Please try again.\n");
    }

    return 0;
}