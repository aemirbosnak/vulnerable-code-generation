//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH+1];
    int password_length;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;
    int score = 0;
    int i;

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH+1, stdin);
    password_length = strlen(password);

    // remove newline character from input
    password[password_length-1] = '\0';

    for (i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?' || password[i] == '^' || password[i] == '~') {
                has_special_character = 1;
            }
        }
    }

    if (password_length >= 8) {
        score += 1;
    }

    if (has_uppercase) {
        score += 1;
    }

    if (has_lowercase) {
        score += 1;
    }

    if (has_number) {
        score += 1;
    }

    if (has_special_character) {
        score += 1;
    }

    printf("Password score: %d\n", score);

    return 0;
}