//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 8
#define PASSWORD_COMPLEXITY 3

int isPasswordComplex(char *password) {
    int complexity = 0;
    int hasDigit = 0;
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (isupper(password[i])) {
            hasUpperCase = 1;
        } else if (islower(password[i])) {
            hasLowerCase = 1;
        } else {
            hasSpecialChar = 1;
        }
        complexity++;
    }

    if (complexity >= PASSWORD_COMPLEXITY) {
        return 1;
    }

    return 0;
}

void generatePassword(char *password) {
    int hasDigit = 0;
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        char c = rand() % 94 + 33;
        password[i] = c;

        if (isdigit(c)) {
            hasDigit = 1;
        } else if (isupper(c)) {
            hasUpperCase = 1;
        } else if (islower(c)) {
            hasLowerCase = 1;
        } else {
            hasSpecialChar = 1;
        }
    }
}

int main() {
    char password[PASSWORD_LENGTH + 1];
    int complexity = 0;

    srand(time(NULL));

    do {
        generatePassword(password);
    } while (!isPasswordComplex(password));

    printf("Your new password is: %s\n", password);

    return 0;
}