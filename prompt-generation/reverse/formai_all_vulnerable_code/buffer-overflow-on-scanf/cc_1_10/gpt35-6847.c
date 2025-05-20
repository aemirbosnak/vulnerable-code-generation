//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MIN_PASSWORD_LENGTH 6 // Minimum password length

int checkPasswordStrength(char* password) {

    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short.\nMinimum length is %d.\n", MIN_PASSWORD_LENGTH);
        return 0;
    }

    // Initialize strength based on password length
    int strength = length * 4;

    int countLower = 0, countUpper = 0, countDigit = 0, countSpecial = 0;
    for (int i = 0; i < length; i++) {
        
        // Count lowercase letters
        if (islower(password[i])) {
            countLower++;
        }

        // Count uppercase letters
        if (isupper(password[i])) {
            countUpper++;
        }

        // Count digits
        if (isdigit(password[i])) {
            countDigit++;
        }

        // Count special characters
        if (!isalnum(password[i])) {
            countSpecial++;
        }
    }

    // Deduct strength points for weak passwords
    if (countLower == 0 || countUpper == 0 || countDigit == 0 || countSpecial == 0) {
        strength -= 20;
    }

    // Deduct additional strength points for repeating characters
    int repeatCount = 0;
    for (int i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            repeatCount++;
        }
    }
    strength -= repeatCount * 5;

    // Assign a strength label based on the final strength score
    char* strengthLabel;
    if (strength < 20) {
        strengthLabel = "Very weak";
    }
    else if (strength < 40) {
        strengthLabel = "Weak";
    }
    else if (strength < 60) {
        strengthLabel = "Moderate";
    }
    else if (strength < 80) {
        strengthLabel = "Strong";
    }
    else {
        strengthLabel = "Very strong";
    }

    // Print strength report
    printf("Password: %s\n", password);
    printf("Length: %d\n", length);
    printf("Lowercase letters: %d\n", countLower);
    printf("Uppercase letters: %d\n", countUpper);
    printf("Digits: %d\n", countDigit);
    printf("Special characters: %d\n", countSpecial);
    printf("Repeating characters: %d\n", repeatCount);
    printf("Strength: %d (%s)\n", strength, strengthLabel);

    return 1;
}

int main() {

    char password[100];
    printf("Enter password to check (minimum length %d): ", MIN_PASSWORD_LENGTH);
    scanf("%s", password);

    checkPasswordStrength(password);

    return 0;
}