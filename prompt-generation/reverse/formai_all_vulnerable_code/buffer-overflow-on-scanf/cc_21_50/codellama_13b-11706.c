//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
/*
 * C Password Strength Checker
 *
 * This program checks the strength of a password and returns a score
 * based on its complexity.
 */

#include <stdio.h>
#include <string.h>

// Function to check the strength of a password
int check_password_strength(char *password) {
    int score = 0;

    // Check if password is at least 8 characters long
    if (strlen(password) >= 8) {
        score++;
    }

    // Check if password contains at least one number
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
        score++;
    }

    // Check if password contains at least one uppercase letter
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') || strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') || strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') || strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') || strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') || strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') || strchr(password, 'Y') || strchr(password, 'Z')) {
        score++;
    }

    // Check if password contains at least one lowercase letter
    if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') || strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') || strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') || strchr(password, 'j') || strchr(password, 'k') || strchr(password, 'l') || strchr(password, 'm') || strchr(password, 'n') || strchr(password, 'o') || strchr(password, 'p') || strchr(password, 'q') || strchr(password, 'r') || strchr(password, 's') || strchr(password, 't') || strchr(password, 'u') || strchr(password, 'v') || strchr(password, 'w') || strchr(password, 'x') || strchr(password, 'y') || strchr(password, 'z')) {
        score++;
    }

    // Check if password contains at least one special character
    if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*') || strchr(password, '(') || strchr(password, ')') || strchr(password, '-') || strchr(password, '_') || strchr(password, '=') || strchr(password, '+') || strchr(password, '[')) {
        score++;
    }

    return score;
}

int main() {
    char password[100];
    int score;

    printf("Enter a password: ");
    scanf("%s", password);

    score = check_password_strength(password);

    if (score == 0) {
        printf("The password is weak.\n");
    } else if (score == 1) {
        printf("The password is moderate.\n");
    } else if (score == 2) {
        printf("The password is strong.\n");
    } else if (score == 3) {
        printf("The password is very strong.\n");
    } else if (score == 4) {
        printf("The password is extremely strong.\n");
    }

    return 0;
}