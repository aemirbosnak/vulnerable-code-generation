//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Function to check if the password contains at least one uppercase letter
bool has_uppercase(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one lowercase letter
bool has_lowercase(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one digit
bool has_digit(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one special character
bool has_special_char(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check the strength of the password
int check_password_strength(char* password) {
    int strength = 0;
    if (has_uppercase(password)) {
        strength++;
    }
    if (has_lowercase(password)) {
        strength++;
    }
    if (has_digit(password)) {
        strength++;
    }
    if (has_special_char(password)) {
        strength++;
    }
    if (strength == 0) {
        return 0;
    }
    if (strength == 1) {
        return 1;
    }
    if (strength == 2) {
        return 2;
    }
    if (strength == 3) {
        return 3;
    }
    return 4;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}