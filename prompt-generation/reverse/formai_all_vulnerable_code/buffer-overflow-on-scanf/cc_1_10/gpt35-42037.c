//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isLowerCase(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

bool isUpperCase(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isSpecialCharacter(char ch) {
    return ((ch >= '!' && ch <= '/') ||
            (ch >= ':' && ch <= '@') ||
            (ch >= '[' && ch <= ']') ||
            (ch >= '{' && ch <= '~'));
}

int calculatePasswordScore(char password[]) {
    int score = 0;
    int i, len = strlen(password);
    bool hasLowerCase = false, hasUpperCase = false, hasDigit = false, hasSpecialCharacter = false;

    for (i = 0; i < len; i++) {
        char ch = password[i];
        if (isLowerCase(ch))
            hasLowerCase = true;
        else if (isUpperCase(ch))
            hasUpperCase = true;
        else if (isDigit(ch))
            hasDigit = true;
        else if (isSpecialCharacter(ch))
            hasSpecialCharacter = true;
    }
    if (hasLowerCase) score++;
    if (hasUpperCase) score++;
    if (hasDigit) score++;
    if (hasSpecialCharacter) score++;

    if (len >= 8) score++;
    if (len >= 12) score++;
    if (len >= 16) score++;

    return score;
}

int main() {
    char password[100];
    int score;

    printf("Enter the password: ");
    scanf("%s", password);

    score = calculatePasswordScore(password);

    printf("Password Strength: ");
    switch (score) {
        case 0:
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("Very Strong\n");
            break;
    }

    return 0;
}