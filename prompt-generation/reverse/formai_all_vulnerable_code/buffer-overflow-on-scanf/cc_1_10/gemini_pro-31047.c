//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

typedef enum {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
} StrengthLevel;

bool containsDigit(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool containsLowercase(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool containsUppercase(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool containsSpecialCharacter(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

int calculateScore(const char *password) {
    int score = 0;

    if (strlen(password) >= MIN_LENGTH && strlen(password) <= MAX_LENGTH) {
        score += 4;
    }

    if (containsDigit(password)) {
        score += 4;
    }

    if (containsLowercase(password)) {
        score += 4;
    }

    if (containsUppercase(password)) {
        score += 4;
    }

    if (containsSpecialCharacter(password)) {
        score += 4;
    }

    return score;
}

StrengthLevel assessStrength(int score) {
    if (score < 12) {
        return WEAK;
    } else if (score < 18) {
        return MEDIUM;
    } else if (score < 24) {
        return STRONG;
    } else {
        return VERY_STRONG;
    }
}

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter password: ");
    scanf("%s", password);

    int score = calculateScore(password);
    StrengthLevel strength = assessStrength(score);

    printf("Password strength: ");
    switch (strength) {
        case WEAK:
            printf("Weak\n");
            break;
        case MEDIUM:
            printf("Medium\n");
            break;
        case STRONG:
            printf("Strong\n");
            break;
        case VERY_STRONG:
            printf("Very strong\n");
            break;
    }

    return 0;
}