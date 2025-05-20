//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 12
#define NUM_OF_ALPHABETS 26
#define NUM_OF_SYMBOLS 8
#define NUM_OF_DIGITS 10
#define NUM_OF_SPECIAL_CHARACTERS 6

int checkPasswordStrength(const char* password) {
    int passwordLength = strlen(password);
    int minLength = MIN_PASSWORD_LENGTH;
    int maxLength = MAX_PASSWORD_LENGTH;
    int numAlphabets = 0;
    int numSymbols = 0;
    int numDigits = 0;
    int numSpecialChars = 0;

    for (int i = 0; i < passwordLength; i++) {
        char ch = password[i];
        if (isalpha(ch)) {
            numAlphabets++;
        } else if (isdigit(ch)) {
            numDigits++;
        } else if (isalpha(ch) || isdigit(ch) || isspace(ch)) {
            continue;
        } else if (isprint(ch)) {
            continue;
        } else {
            numSpecialChars++;
        }
    }

    if (passwordLength >= minLength && passwordLength <= maxLength) {
        if (numAlphabets >= NUM_OF_ALPHABETS && numSymbols >= NUM_OF_SYMBOLS && numDigits >= NUM_OF_DIGITS && numSpecialChars >= NUM_OF_SPECIAL_CHARACTERS) {
            return 1; // Strong password
        } else {
            return 0; // Weak password
        }
    } else {
        return 0; // Invalid password length
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    int passwordStrength = checkPasswordStrength(password);

    if (passwordStrength == 1) {
        printf("Password is strong.\n");
    } else if (passwordStrength == 0) {
        printf("Password is weak.\n");
    } else {
        printf("Invalid password length.\n");
    }

    return 0;
}