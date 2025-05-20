//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int i, len, strengthScore = 0;

    printf("Welcome to the Password Strength Checker! \n");
    printf("Please enter your password: ");
    scanf("%s", password);

    len = strlen(password);

    // Check if password contains at least 1 uppercase letter
    for(i = 0; i < len; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            strengthScore += 10; // Add 10 points
            break; // Only need 1 uppercase letter, so exit loop
        }
    }

    // Check if password contains at least 1 lowercase letter
    for(i = 0; i < len; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            strengthScore += 10; // Add 10 points
            break; // Only need 1 lowercase letter, so exit loop
        }
    }

    // Check if password contains at least 1 digit
    for(i = 0; i < len; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            strengthScore += 10; // Add 10 points
            break; // Only need 1 digit, so exit loop
        }
    }

    // Check if password contains at least 1 special character
    for(i = 0; i < len; i++) {
        if(!(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= '0' && password[i] <= '9')) {
            strengthScore += 10; // Add 10 points
            break; // Only need 1 special character, so exit loop
        }
    }

    // Check overall strength score and provide feedback
    if(strengthScore < 30) {
        printf("Your password is weak and easily guessable. Please consider a new password.\n");
    }
    else if(strengthScore >= 30 && strengthScore < 70) {
        printf("Your password is moderate, but still could be stronger. Consider adding more complexity to your password.\n");
    }
    else {
        printf("Congratulations! Your password is strong and secure.\n");
    }

    return 0;
}