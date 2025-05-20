//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length = 0;
    int lowercase = 0;
    int uppercase = 0;
    int numbers = 0;
    int symbols = 0;

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character
    if (password[length - 1] == '\n')
        password[length - 1] = '\0';

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                uppercase = 1;
            } else {
                lowercase = 1;
            }
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else {
            symbols = 1;
        }
    }

    int score = 0;

    if (length >= 8) {
        score += 1;
    }

    if (lowercase) {
        score += 1;
    }

    if (uppercase) {
        score += 1;
    }

    if (numbers) {
        score += 1;
    }

    if (symbols) {
        score += 1;
    }

    printf("Password strength: ");

    if (score == 0) {
        printf("Very Weak\n");
    } else if (score == 1) {
        printf("Weak\n");
    } else if (score == 2) {
        printf("Moderate\n");
    } else if (score == 3) {
        printf("Strong\n");
    } else if (score == 4) {
        printf("Very Strong\n");
    }

    return 0;
}