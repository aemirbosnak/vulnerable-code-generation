//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define WEAK_THRESHOLD 3

typedef enum {LOW, MEDIUM, HIGH, VERY_HIGH} PasswordStrength;

void convertToLower(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

bool containsDigit(char *str, int length) {
    for (int i = 0; i < length; i++) {
        if (isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

bool containsSpecialCharacter(char *str, int length) {
    const char *specialCharacters = "!@#$%^&*()_+-={}[]|\\:\"<>,.?/~`";

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(specialCharacters); j++) {
            if (str[i] == specialCharacters[j]) {
                return true;
            }
        }
    }
    return false;
}

bool checkPasswordStrength(char *password, int length) {
    PasswordStrength strength = LOW;

    if (length < MIN_LENGTH) {
        printf("Password length is too short. Minimum length is %d.\n", MIN_LENGTH);
        return false;
    }

    convertToLower(password, length);

    if (containsDigit(password, length) && containsSpecialCharacter(password, length)) {
        strength = VERY_HIGH;
    } else if (containsDigit(password, length) || containsSpecialCharacter(password, length)) {
        strength = HIGH;
    } else {
        strength = MEDIUM;
    }

    int digitsCount = 0, specialCharsCount = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digitsCount++;
        }

        if (containsSpecialCharacter(password, length) && password[i] == password[i]) {
            specialCharsCount++;
        }
    }

    if (digitsCount < WEAK_THRESHOLD || specialCharsCount < WEAK_THRESHOLD) {
        if (strength == VERY_HIGH) {
            strength = HIGH;
        } else if (strength == HIGH) {
            strength = MEDIUM;
        }
    }

    return strength;
}

int main() {
    char password[128];
    int length;
    PasswordStrength strength;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    strength = checkPasswordStrength(password, length);

    switch (strength) {
        case LOW:
            printf("Password is weak.\n");
            break;
        case MEDIUM:
            printf("Password is medium.\n");
            break;
        case HIGH:
            printf("Password is strong.\n");
            break;
        case VERY_HIGH:
            printf("Password is very strong.\n");
            break;
    }

    return 0;
}