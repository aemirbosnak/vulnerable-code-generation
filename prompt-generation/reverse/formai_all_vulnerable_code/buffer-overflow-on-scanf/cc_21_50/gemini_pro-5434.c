//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    int passwordStrength = 0;

    // Check the length of the password
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        printf("Password is too short. It must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Password is too long. It must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
    } else {
        passwordStrength++;
    }

    // Check if the password contains any uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        passwordStrength++;
    }

    // Check if the password contains any lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        passwordStrength++;
    }

    // Check if the password contains any digits
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (hasDigit) {
        passwordStrength++;
    }

    // Check if the password contains any special characters
    int hasSpecialCharacter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '!' && password[i] <= '/') {
            hasSpecialCharacter = 1;
            break;
        } else if (password[i] >= ':' && password[i] <= '@') {
            hasSpecialCharacter = 1;
            break;
        } else if (password[i] >= '[' && password[i] <= '`') {
            hasSpecialCharacter = 1;
            break;
        } else if (password[i] >= '{' && password[i] <= '~') {
            hasSpecialCharacter = 1;
            break;
        }
    }
    if (hasSpecialCharacter) {
        passwordStrength++;
    }

    // Print the password strength
    switch (passwordStrength) {
        case 0:
            printf("Password is very weak.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
        case 5:
            printf("Password is extremely strong.\n");
            break;
    }

    return 0;
}