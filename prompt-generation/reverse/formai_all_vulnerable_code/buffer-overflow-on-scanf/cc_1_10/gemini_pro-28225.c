//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is uppercase
int isUpper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

// Function to check if a character is lowercase
int isLower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

// Function to check if a character is a digit
int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Function to check if a character is a special character
int isSpecialChar(char ch) {
    return (!isUpper(ch) && !isLower(ch) && !isDigit(ch));
}

// Function to calculate the strength of a password
int calculatePasswordStrength(char* password) {
    int score = 0;
    int length = strlen(password);

    // Check the length of the password
    if (length < 8) {
        score += 1;
    } else if (length >= 12) {
        score += 3;
    }

    // Check if the password contains uppercase characters
    for (int i = 0; i < length; i++) {
        if (isUpper(password[i])) {
            score += 1;
            break;
        }
    }

    // Check if the password contains lowercase characters
    for (int i = 0; i < length; i++) {
        if (isLower(password[i])) {
            score += 1;
            break;
        }
    }

    // Check if the password contains digits
    for (int i = 0; i < length; i++) {
        if (isDigit(password[i])) {
            score += 1;
            break;
        }
    }

    // Check if the password contains special characters
    for (int i = 0; i < length; i++) {
        if (isSpecialChar(password[i])) {
            score += 1;
            break;
        }
    }

    return score;
}

// Function to print the strength of a password
void printPasswordStrength(int score) {
    switch (score) {
        case 0:
            printf("Very weak");
            break;
        case 1:
            printf("Weak");
            break;
        case 2:
            printf("Moderate");
            break;
        case 3:
            printf("Strong");
            break;
        case 4:
            printf("Very strong");
            break;
        default:
            printf("Invalid password");
    }
}

int main() {
    char password[100];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculate the strength of the password
    int score = calculatePasswordStrength(password);

    // Print the strength of the password
    printf("The strength of the password is: ");
    printPasswordStrength(score);

    return 0;
}