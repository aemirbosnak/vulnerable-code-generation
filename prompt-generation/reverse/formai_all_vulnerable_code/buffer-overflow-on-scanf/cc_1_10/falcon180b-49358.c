//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Function to check if password contains at least one uppercase letter
int contains_uppercase(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains at least one lowercase letter
int contains_lowercase(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains at least one digit
int contains_digit(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains at least one special character
int contains_special(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check password strength
int check_password_strength(char* password) {
    int strength = 0;

    // Check for minimum password length
    if (strlen(password) >= MIN_PASSWORD_LENGTH) {
        strength++;
    }

    // Check for uppercase letter
    if (contains_uppercase(password)) {
        strength++;
    }

    // Check for lowercase letter
    if (contains_lowercase(password)) {
        strength++;
    }

    // Check for digit
    if (contains_digit(password)) {
        strength++;
    }

    // Check for special character
    if (contains_special(password)) {
        strength++;
    }

    // Return password strength
    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    int strength = check_password_strength(password);

    // Print password strength
    switch(strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Moderate\n");
            break;
        case 2:
            printf("Strong\n");
            break;
        case 3:
            printf("Very strong\n");
            break;
        case 4:
            printf("Excellent\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    return 0;
}