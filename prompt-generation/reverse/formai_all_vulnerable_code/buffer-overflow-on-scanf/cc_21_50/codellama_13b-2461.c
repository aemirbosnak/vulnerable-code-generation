//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: brave
/*
 * C Password Strength Checker
 *
 * This program checks the strength of a given password and provides a score
 * based on its complexity.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password
    if (strlen(password) >= 8) {
        score++;
    }

    // Check for uppercase and lowercase letters
    if (strchr(password, 'A') || strchr(password, 'a')) {
        score++;
    }
    if (strchr(password, 'Z') || strchr(password, 'z')) {
        score++;
    }

    // Check for numbers
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') ||
        strchr(password, '3') || strchr(password, '4') || strchr(password, '5') ||
        strchr(password, '6') || strchr(password, '7') || strchr(password, '8') ||
        strchr(password, '9')) {
        score++;
    }

    // Check for special characters
    if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') ||
        strchr(password, '$') || strchr(password, '%') || strchr(password, '^') ||
        strchr(password, '&') || strchr(password, '*') || strchr(password, '-') ||
        strchr(password, '+') || strchr(password, '=') || strchr(password, '?') ||
        strchr(password, '/') || strchr(password, '\\') || strchr(password, '|') ||
        strchr(password, '~')) {
        score++;
    }

    // Print the score
    printf("Your password score is %d out of 4.\n", score);

    return 0;
}