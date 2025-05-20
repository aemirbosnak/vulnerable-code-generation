//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 6
#define WEAK 0
#define MODERATE 1
#define STRONG 2
#define VERY_STRONG 3

int calculate_score(const char* password) {
    size_t length = strlen(password);
    int score = 0;

    // Length check
    if (length < MIN_LENGTH)
        score += 1;
    else if (length <= 9)
        score += 2;
    else if (length <= 15)
        score += 3;
    else
        score += 4;

    // Check for presence of lowercase letters
    for (size_t i = 0; password[i]; i++) {
        if (islower(password[i]))
            score += 1;
    }

    // Check for presence of uppercase letters
    for (size_t i = 0; password[i]; i++) {
        if (isupper(password[i]))
            score += 1;
    }

    // Check for presence of digits
    for (size_t i = 0; password[i]; i++) {
        if (isdigit(password[i]))
            score += 1;
    }

    // Check for presence of common patterns
    if (strstr(password, "password") || strstr(password, "123456") ||
        strstr(password, "qwerty") || strstr(password, "letmein") ||
        strstr(password, "admin") || strstr(password, "111111") ||
        strstr(password, "12345") || strstr(password, "121212"))
        score -= 5;

    return score;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    const char* password = argv[1];
    int score = calculate_score(password);

    switch (score) {
        case WEAK:
            printf("Weak\n");
            break;
        case MODERATE:
            printf("Moderate\n");
            break;
        case STRONG:
            printf("Strong\n");
            break;
        case VERY_STRONG:
            printf("Very Strong\n");
            break;
        default:
            printf("Unknown score: %d\n", score);
            break;
    }

    return 0;
}