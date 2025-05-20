//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a unique surreal password strength checker
int surreal_password_strength_checker(char *password) {
    int length = strlen(password);
    int score = 0;

    // Count the number of unique characters in the password
    int unique_chars = 0;
    for (int i = 0; i < length; i++) {
        int unique = 1;
        for (int j = i+1; j < length; j++) {
            if (password[i] == password[j]) {
                unique = 0;
                break;
            }
        }
        if (unique) unique_chars++;
    }

    // If the password is longer than 10 characters and contains at least 3 unique characters, add 10 points
    if (length > 10 && unique_chars >= 3) {
        score += 10;
    }

    // If the password contains at least one lowercase letter and one uppercase letter, add 5 points
    int lowercase = 0;
    int uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') lowercase = 1;
        if (password[i] >= 'A' && password[i] <= 'Z') uppercase = 1;
    }
    if (lowercase && uppercase) {
        score += 5;
    }

    // If the password contains at least one digit and one special character, add 7 points
    int digit = 0;
    int special = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') digit = 1;
        if (password[i] >= 33 && password[i] <= 47) special = 1;
        if (password[i] >= 58 && password[i] <= 64) special = 1;
        if (password[i] >= 91 && password[i] <= 96) special = 1;
        if (password[i] >= 123 && password[i] <= 126) special = 1;
    }
    if (digit && special) {
        score += 7;
    }

    // Return the password strength score
    return score;
}

// Invoke the surreal password strength checker with a random password
int main() {
    char *password = malloc(11 * sizeof(char));
    strcpy(password, "xOcNhT$!lN");
    int score = surreal_password_strength_checker(password);
    printf("The surreal password strength score is: %d\n", score);
    free(password);
    return 0;
}