//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define MIN_NUMERIC_DIGITS 1
#define MIN_SYMBOLS 1
#define MIN_UPPERCASE_LETTERS 1
#define MIN_LOWERCASE_LETTERS 1

int isPasswordValid(char *password) {
    int length = strlen(password);
    int hasNumericDigits = 0;
    int hasSymbols = 0;
    int hasUppercaseLetters = 0;
    int hasLowercaseLetters = 0;

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Password must be between %d and %d characters long\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasNumericDigits++;
        } else if (isalpha(password[i])) {
            if (isupper(password[i])) {
                hasUppercaseLetters++;
            } else {
                hasLowercaseLetters++;
            }
        } else {
            hasSymbols++;
        }
    }

    if (hasNumericDigits < MIN_NUMERIC_DIGITS) {
        printf("Password must have at least %d numeric digits\n", MIN_NUMERIC_DIGITS);
        return 0;
    }

    if (hasSymbols < MIN_SYMBOLS) {
        printf("Password must have at least %d symbols\n", MIN_SYMBOLS);
        return 0;
    }

    if (hasUppercaseLetters < MIN_UPPERCASE_LETTERS) {
        printf("Password must have at least %d uppercase letters\n", MIN_UPPERCASE_LETTERS);
        return 0;
    }

    if (hasLowercaseLetters < MIN_LOWERCASE_LETTERS) {
        printf("Password must have at least %d lowercase letters\n", MIN_LOWERCASE_LETTERS);
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is valid\n");
    } else {
        printf("Password is not valid\n");
    }

    return 0;
}