//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Constants
#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGITS 1
#define MIN_SPECIAL 1

// Function to check password strength
int checkPasswordStrength(char *password) {
    int score = 0;

    // Check password length
    if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH) {
        return score;
    } score += 4;

    // Check for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        score += 2;
    }

    // Check for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        score += 2;
    }

    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }
    if (hasDigit) {
        score += 2;
    }

    // Check for special characters
    int hasSpecial = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            hasSpecial = 1;
            break;
        }
    }
    if (hasSpecial) {
        score += 2;
    }

    // Check for consecutive characters
    for (int i = 0; i < strlen(password) - 1; i++) {
        if (password[i] == password[i + 1]) {
            score -= 1;
        }
    }

    return score;
}

int main() {
    // Get password from user
    char password[MAX_LENGTH + 1];
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    int score = checkPasswordStrength(password);

    // Print password strength
    printf("Password strength: ");
    switch (score) {
        case 0:
            printf("Very weak");
            break;
        case 1:
        case 2:
            printf("Weak");
            break;
        case 3:
        case 4:
            printf("Medium");
            break;
        case 5:
        case 6:
            printf("Strong");
            break;
        case 7:
        case 8:
            printf("Very strong");
            break;
        default:
            printf("Invalid password");
    }
    printf("\n");

    return 0;
}