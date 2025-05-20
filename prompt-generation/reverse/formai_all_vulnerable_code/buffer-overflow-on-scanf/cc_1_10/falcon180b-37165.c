//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8
#define MIN_LOWER 1
#define MIN_UPPER 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

int isValidPassword(char *password);
int countChars(char *password, char c);

int main() {
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (isValidPassword(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

int isValidPassword(char *password) {
    int hasLower = 0;
    int hasUpper = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    int length = strlen(password);

    if (length < PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                hasLower = 1;
            } else if (isupper(password[i])) {
                hasUpper = 1;
            }
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    return (hasLower && hasUpper && hasDigit && hasSpecial);
}

int countChars(char *password, char c) {
    int count = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == c) {
            count++;
        }
    }

    return count;
}