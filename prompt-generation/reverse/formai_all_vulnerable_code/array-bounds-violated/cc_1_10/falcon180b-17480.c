//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Get user input
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character
    length = strlen(password);
    password[length - 1] = '\0';

    // Check password strength
    int uppercase = 0, lowercase = 0, numbers = 0, special = 0;
    int score = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else {
            special = 1;
        }
    }

    if (length >= 8) {
        score += 1;
    }

    if (uppercase) {
        score += 1;
    }

    if (lowercase) {
        score += 1;
    }

    if (numbers) {
        score += 1;
    }

    if (special) {
        score += 1;
    }

    printf("Your password strength score is: %d\n", score);

    return 0;
}