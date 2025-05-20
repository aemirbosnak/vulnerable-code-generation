//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if the password contains at least one uppercase letter
int contains_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int contains_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one digit
int contains_digit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one special character
int contains_special_character(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check the strength of the password
int check_password_strength(char *password) {
    int strength = 0;
    if (contains_uppercase(password)) {
        strength++;
    }
    if (contains_lowercase(password)) {
        strength++;
    }
    if (contains_digit(password)) {
        strength++;
    }
    if (contains_special_character(password)) {
        strength++;
    }
    if (strlen(password) >= 8) {
        strength++;
    }
    if (strength == 0) {
        printf("Weak password\n");
    } else if (strength == 1) {
        printf("Moderate password\n");
    } else if (strength == 2) {
        printf("Strong password\n");
    } else if (strength == 3) {
        printf("Very strong password\n");
    } else {
        printf("Invalid password\n");
    }
    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    return 0;
}