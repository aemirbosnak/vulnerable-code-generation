//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int isStrongPassword(char *password) {
    int score = 0;
    int length = strlen(password);

    // Check the length of the password
    if (length < 8) {
        score += 1;
    }

    // Check for uppercase characters
    int hasUppercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (!hasUppercase) {
        score += 1;
    }

    // Check for lowercase characters
    int hasLowercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (!hasLowercase) {
        score += 1;
    }

    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        score += 1;
    }

    // Check for special characters
    int hasSpecialCharacter = 0;
    for (int i = 0; i < length; i++) {
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`')) {
            hasSpecialCharacter = 1;
            break;
        }
    }
    if (!hasSpecialCharacter) {
        score += 1;
    }

    // Calculate the final score
    int finalScore = 5 - score;

    // Return the final score
    return finalScore;
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int score = isStrongPassword(password);

    // Print the strength of the password
    printf("Your password strength is: ");
    switch (score) {
        case 1:
            printf("Very weak");
            break;
        case 2:
            printf("Weak");
            break;
        case 3:
            printf("Fair");
            break;
        case 4:
            printf("Good");
            break;
        case 5:
            printf("Excellent");
            break;
    }

    printf("\n");

    return 0;
}