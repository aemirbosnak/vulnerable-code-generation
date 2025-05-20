//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

enum Strength {
    TooShort,
    Weak,
    Moderate,
    Strong,
    VeryStrong
};

bool isValidPassword(char *password) {
    int length = strlen(password);

    if (length < 8) {
        return false;
    }

    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    int symbolCount = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            uppercaseCount++;
        } else if (islower(c)) {
            lowercaseCount++;
        } else if (isdigit(c)) {
            digitCount++;
        } else {
            symbolCount++;
        }
    }

    if (uppercaseCount == 0 || lowercaseCount == 0 || digitCount == 0 || symbolCount == 0) {
        return false;
    }

    return true;
}

enum Strength getStrength(char *password) {
    int length = strlen(password);

    if (!isValidPassword(password)) {
        return TooShort;
    } else if (length < 12) {
        return Weak;
    } else if (length < 16) {
        return Moderate;
    } else if (length < 20) {
        return Strong;
    } else {
        return VeryStrong;
    }
}

void printStrength(enum Strength strength) {
    switch (strength) {
        case TooShort:
            printf("Your password is too short.\n");
            break;
        case Weak:
            printf("Your password is weak.\n");
            break;
        case Moderate:
            printf("Your password is moderate.\n");
            break;
        case Strong:
            printf("Your password is strong.\n");
            break;
        case VeryStrong:
            printf("Your password is very strong.\n");
            break;
    }
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    enum Strength strength = getStrength(password);

    printStrength(strength);

    return 0;
}