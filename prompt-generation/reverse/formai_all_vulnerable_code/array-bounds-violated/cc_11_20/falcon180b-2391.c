//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i;

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove trailing newline character
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    if (length <= 0 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    int score = 0;

    if (has_uppercase) {
        score++;
    }

    if (has_lowercase) {
        score++;
    }

    if (has_digit) {
        score++;
    }

    if (has_special) {
        score++;
    }

    if (score == 0) {
        printf("Very weak password.\n");
    } else if (score == 1) {
        printf("Weak password.\n");
    } else if (score == 2) {
        printf("Moderate password.\n");
    } else if (score == 3) {
        printf("Strong password.\n");
    } else if (score == 4) {
        printf("Very strong password.\n");
    }

    return 0;
}