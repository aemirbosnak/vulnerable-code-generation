//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: creative
// C Password Strength Checker
#include <stdio.h>
#include <string.h>

// Function to check password strength
int check_password_strength(char *password) {
    int score = 0;
    int password_length = strlen(password);
    if (password_length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    if (strchr(password, ' ')) {
        printf("Password must not contain any spaces.\n");
        return 0;
    }
    if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') ||
        strchr(password, '$') || strchr(password, '%') || strchr(password, '^') ||
        strchr(password, '&') || strchr(password, '*') || strchr(password, '(') ||
        strchr(password, ')') || strchr(password, '-') || strchr(password, '_') ||
        strchr(password, '+') || strchr(password, '=') || strchr(password, '{') ||
        strchr(password, '}') || strchr(password, '[')) {
        score++;
    }
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') ||
        strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') ||
        strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') ||
        strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') ||
        strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') ||
        strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') ||
        strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') ||
        strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') ||
        strchr(password, 'Y') || strchr(password, 'Z')) {
        score++;
    }
    if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') ||
        strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') ||
        strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') ||
        strchr(password, 'j') || strchr(password, 'k') || strchr(password, 'l') ||
        strchr(password, 'm') || strchr(password, 'n') || strchr(password, 'o') ||
        strchr(password, 'p') || strchr(password, 'q') || strchr(password, 'r') ||
        strchr(password, 's') || strchr(password, 't') || strchr(password, 'u') ||
        strchr(password, 'v') || strchr(password, 'w') || strchr(password, 'x') ||
        strchr(password, 'y') || strchr(password, 'z')) {
        score++;
    }
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') ||
        strchr(password, '3') || strchr(password, '4') || strchr(password, '5') ||
        strchr(password, '6') || strchr(password, '7') || strchr(password, '8') ||
        strchr(password, '9')) {
        score++;
    }
    if (score < 3) {
        printf("Password must contain at least 3 of the following: uppercase letter, lowercase letter, number, and special character.\n");
        return 0;
    }
    return 1;
}

// Main function
int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    if (check_password_strength(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    return 0;
}