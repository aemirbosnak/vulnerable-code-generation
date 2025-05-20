//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK 0
#define MODERATE 1
#define STRONG 2
#define VERY_STRONG 3

int check_length(const char *password) {
    int length = strlen(password);
    return length >= MIN_LENGTH ? STRONG : (length >= 6 ? MODERATE : WEAK);
}

int count_digits(const char *password) {
    int count = 0;
    while (*password) {
        if (isdigit(*password++)) count++;
    }
    return count;
}

int count_uppercase(const char *password) {
    int count = 0;
    while (*password) {
        if (isupper(*password++)) count++;
    }
    return count;
}

int count_lowercase(const char *password) {
    int count = 0;
    while (*password) {
        if (islower(*password++)) count++;
    }
    return count;
}

int check_complexity(const char *password) {
    int length = strlen(password);
    int digits = count_digits(password);
    int uppercase = count_uppercase(password);
    int lowercase = count_lowercase(password);

    if (length >= 12) return VERY_STRONG;
    if (digits >= 3 && uppercase >= 3 && lowercase >= 3) return STRONG;
    if (digits >= 2 && (uppercase || lowercase)) return MODERATE;

    return WEAK;
}

int main(void) {
    char password[128];
    int level;

    printf("Enter your password: ");
    scanf("%s", password);

    level = check_length(password);
    if (level > WEAK) {
        level = check_complexity(password);
        printf("Password complexity level: ");
        switch (level) {
            case WEAK: printf("Weak\n"); break;
            case MODERATE: printf("Moderate\n"); break;
            case STRONG: printf("Strong\n"); break;
            case VERY_STRONG: printf("Very Strong\n"); break;
        }
    } else {
        printf("Password length is too short.\n");
    }

    return 0;
}