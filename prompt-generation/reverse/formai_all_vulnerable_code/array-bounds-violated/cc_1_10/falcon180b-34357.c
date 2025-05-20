//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Get user input for password
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from input
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }

    // Check password strength
    int score = 0;
    if (length >= 8) {
        score++;
    }
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") > 0) {
        score++;
    }
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") > 0) {
        score++;
    }
    if (strspn(password, "0123456789") > 0) {
        score++;
    }
    if (strspn(password, "!@#$%^&*()-_+=[]{}\\|;:'\",.<>/?") > 0) {
        score++;
    }

    if (score == 0) {
        printf("Weak password\n");
    } else if (score == 1) {
        printf("Fair password\n");
    } else if (score == 2) {
        printf("Good password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}