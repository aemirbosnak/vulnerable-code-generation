//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 50

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove newline character
    password[length - 1] = '\0';

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else if (!isalnum(password[i])) {
            has_special_char = 1;
        }
    }

    int score = 0;

    if (length >= 8) {
        score += 1;
    }

    if (has_uppercase) {
        score += 1;
    }

    if (has_lowercase) {
        score += 1;
    }

    if (has_digit) {
        score += 1;
    }

    if (has_special_char) {
        score += 1;
    }

    printf("Password strength: ");

    if (score == 0) {
        printf("Very weak\n");
    } else if (score == 1) {
        printf("Weak\n");
    } else if (score == 2) {
        printf("Fair\n");
    } else if (score == 3) {
        printf("Good\n");
    } else if (score == 4) {
        printf("Strong\n");
    } else if (score == 5) {
        printf("Very strong\n");
    }

    return 0;
}