//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MIN_LENGTH 8 // minimum password length
#define MAX_LENGTH 16 // maximum password length

int validate_password(char *password);

int main(void) {
    char password[MAX_LENGTH + 1];
    int strength;

    printf("Enter your password: ");
    fgets(password, MAX_LENGTH + 1, stdin);

    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0'; // remove newline character
    }

    strength = validate_password(password);

    switch (strength) {
        case 0:
            printf("Password is too short. Minimum password length is %d.\n", MIN_LENGTH);
            break;
        case 1:
            printf("Password is weak. Strength score: %d.\n", strength);
            break;
        case 2:
            printf("Password is moderate. Strength score: %d.\n", strength);
            break;
        case 3:
            printf("Password is strong. Strength score: %d.\n", strength);
            break;
        case 4:
            printf("Password is very strong. Strength score: %d.\n", strength);
            break;
        default:
            printf("An error has occurred. Please try again.\n");
            break;
    }

    return 0;
}

int validate_password(char *password) {
    int length = strlen(password);
    int score = 0;
    int uppercase = 0, lowercase = 0, digits = 0, symbols = 0;

    if (length < MIN_LENGTH) {
        return 0; // password is too short
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            digits++;
        } else {
            symbols++;
        }
    }

    if (uppercase > 0) {
        score++;
    }

    if (lowercase > 0) {
        score++;
    }

    if (digits > 0) {
        score++;
    }

    if (symbols > 0) {
        score++;
    }

    if (length >= 12) {
        score++;
    }

    return score;
}