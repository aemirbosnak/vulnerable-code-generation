//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>

int checkPasswordStrength(char password[], int n, int score) {
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    if (n == 0) {
        return score;
    }

    // Check if password has lowercase character
    if (password[n-1] >= 'a' && password[n-1] <= 'z') {
        hasLower = 1;
    }
    
    // Check if password has uppercase character
    if (password[n-1] >= 'A' && password[n-1] <= 'Z') {
        hasUpper = 1;
    }

    // Check if password has digit
    if (password[n-1] >= '0' && password[n-1] <= '9') {
        hasDigit = 1;
    }

    // Check if password has special character
    if ((password[n-1] >= '!' && password[n-1] <= '/') ||
        (password[n-1] >= ':' && password[n-1] <= '@') ||
        (password[n-1] >= '[' && password[n-1] <= '`') ||
        (password[n-1] >= '{' && password[n-1] <= '~')) {
        hasSpecial = 1;
    }

    // Increment score based on check results
    if (hasLower && hasUpper && hasDigit && hasSpecial) {
        score += 25;
    }
    else if ((hasLower || hasUpper) && hasDigit && hasSpecial) {
        score += 20;
    }
    else if ((hasLower || hasUpper) && hasDigit) {
        score += 15;
    }
    else if ((hasLower || hasUpper) && hasSpecial) {
        score += 15;
    }
    else if (hasLower || hasUpper) {
        score += 10;
    }
    else if (hasDigit) {
        score += 5;
    }
    else if (hasSpecial) {
        score += 5;
    }

    // Call function recursively to check remaining password characters
    return checkPasswordStrength(password, n-1, score);
}

int main() {
    char password[50];
    int score = 0;

    // Take password input from user
    printf("Enter password: ");
    scanf("%s", password);

    // Calculate password strength score
    score = checkPasswordStrength(password, strlen(password), score);

    // Print password strength score and corresponding message
    printf("Password Strength Score: %d\n", score);
    if (score >= 85) {
        printf("Very Strong Password\n");
    }
    else if (score >= 65) {
        printf("Strong Password\n");
    }
    else if (score >= 45) {
        printf("Moderate Password\n");
    }
    else {
        printf("Weak Password\n");
    }

    return 0;
}