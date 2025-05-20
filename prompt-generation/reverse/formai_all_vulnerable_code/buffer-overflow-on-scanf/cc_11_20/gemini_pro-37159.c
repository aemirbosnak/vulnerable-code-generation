//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Function to check the strength of a password
int checkPassword(char *password) {
    int length = strlen(password);
    int score = 0;

    // Check for minimum length
    if (length < 8) {
        printf("Insufficient length. ");
        return STRENGTH_WEAK;
    } else {
        score++;
    }

    // Check for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        score++;
    }

    // Check for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        score++;
    }

    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }
    if (hasDigit) {
        score++;
    }

    // Check for special characters
    int hasSpecial = 0;
    char specialChars[] = "!@#$%^&*()_-=+";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(specialChars); j++) {
            if (password[i] == specialChars[j]) {
                hasSpecial = 1;
                break;
            }
        }
        if (hasSpecial) {
            break;
        }
    }
    if (hasSpecial) {
        score++;
    }

    // Return the password strength level
    if (score < 3) {
        return STRENGTH_WEAK;
    } else if (score == 3) {
        return STRENGTH_MEDIUM;
    } else {
        return STRENGTH_STRONG;
    }
}

int main() {
    // Get the password from the user
    char password[101];
    printf("Elementary, my dear Watson! Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPassword(password);

    // Print the password strength level
    switch (strength) {
        case STRENGTH_WEAK:
            printf("Insufficient. ");
            printf("Your password is too weak. Please try again.\n");
            break;
        case STRENGTH_MEDIUM:
            printf("Mediocre. ");
            printf("Your password is moderately strong. Consider making it stronger.\n");
            break;
        case STRENGTH_STRONG:
            printf("Excellent. ");
            printf("Your password is very strong. Well done!\n");
            break;
    }

    return 0;
}