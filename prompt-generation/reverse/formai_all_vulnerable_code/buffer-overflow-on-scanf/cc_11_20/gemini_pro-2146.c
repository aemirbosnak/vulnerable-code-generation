//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN_LEN 8
#define MAX_LEN 64

int main() {
    char password[MAX_LEN + 1];
    int len, score;

    printf("Enter a password: ");
    scanf("%s", password);

    len = strlen(password);

    if (len < MIN_LEN) {
        printf("Password is too short\n");
        return 1;
    } else if (len > MAX_LEN) {
        printf("Password is too long\n");
        return 1;
    }

    score = 0;

    // Check for uppercase characters
    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            score++;
        }
    }

    // Check for lowercase characters
    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            score++;
        }
    }

    // Check for digits
    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            score++;
        }
    }

    // Check for special characters
    for (int i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            score++;
        }
    }

    // Check for repeated characters
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (password[i] == password[j]) {
                score--;
            }
        }
    }

    if (score < 5) {
        printf("Password is weak\n");
    } else if (score < 10) {
        printf("Password is fair\n");
    } else if (score < 15) {
        printf("Password is strong\n");
    } else {
        printf("Password is very strong\n");
    }

    return 0;
}