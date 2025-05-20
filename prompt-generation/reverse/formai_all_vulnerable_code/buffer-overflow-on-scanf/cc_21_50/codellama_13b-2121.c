//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 16

int check_password_strength(char *password) {
    int score = 0;

    if (strlen(password) < 8) {
        printf("Password is too short!\n");
        return 0;
    }

    if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*') || strchr(password, '(') || strchr(password, ')') || strchr(password, '-') || strchr(password, '+') || strchr(password, '=') || strchr(password, '[') || strchr(password, ']') || strchr(password, '{') || strchr(password, '}') || strchr(password, '|') || strchr(password, '\\') || strchr(password, '/') || strchr(password, '?') || strchr(password, '<') || strchr(password, '>') || strchr(password, ',') || strchr(password, '.') || strchr(password, ':') || strchr(password, ';') || strchr(password, '\'') || strchr(password, '"')) {
        printf("Password contains invalid characters!\n");
        return 0;
    }

    if (strchr(password, 'a') || strchr(password, 'A')) {
        score++;
    }

    if (strchr(password, 'b') || strchr(password, 'B')) {
        score++;
    }

    if (strchr(password, 'c') || strchr(password, 'C')) {
        score++;
    }

    if (strchr(password, 'd') || strchr(password, 'D')) {
        score++;
    }

    if (strchr(password, 'e') || strchr(password, 'E')) {
        score++;
    }

    if (strchr(password, 'f') || strchr(password, 'F')) {
        score++;
    }

    if (strchr(password, 'g') || strchr(password, 'G')) {
        score++;
    }

    if (strchr(password, 'h') || strchr(password, 'H')) {
        score++;
    }

    if (strchr(password, 'i') || strchr(password, 'I')) {
        score++;
    }

    if (strchr(password, 'j') || strchr(password, 'J')) {
        score++;
    }

    if (strchr(password, 'k') || strchr(password, 'K')) {
        score++;
    }

    if (strchr(password, 'l') || strchr(password, 'L')) {
        score++;
    }

    if (strchr(password, 'm') || strchr(password, 'M')) {
        score++;
    }

    if (strchr(password, 'n') || strchr(password, 'N')) {
        score++;
    }

    if (strchr(password, 'o') || strchr(password, 'O')) {
        score++;
    }

    if (strchr(password, 'p') || strchr(password, 'P')) {
        score++;
    }

    if (strchr(password, 'q') || strchr(password, 'Q')) {
        score++;
    }

    if (strchr(password, 'r') || strchr(password, 'R')) {
        score++;
    }

    if (strchr(password, 's') || strchr(password, 'S')) {
        score++;
    }

    if (strchr(password, 't') || strchr(password, 'T')) {
        score++;
    }

    if (strchr(password, 'u') || strchr(password, 'U')) {
        score++;
    }

    if (strchr(password, 'v') || strchr(password, 'V')) {
        score++;
    }

    if (strchr(password, 'w') || strchr(password, 'W')) {
        score++;
    }

    if (strchr(password, 'x') || strchr(password, 'X')) {
        score++;
    }

    if (strchr(password, 'y') || strchr(password, 'Y')) {
        score++;
    }

    if (strchr(password, 'z') || strchr(password, 'Z')) {
        score++;
    }

    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
        score++;
    }

    if (strlen(password) > 8) {
        score++;
    }

    if (score >= 5) {
        printf("Password is strong!\n");
        return 1;
    } else {
        printf("Password is weak!\n");
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    if (check_password_strength(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }

    return 0;
}