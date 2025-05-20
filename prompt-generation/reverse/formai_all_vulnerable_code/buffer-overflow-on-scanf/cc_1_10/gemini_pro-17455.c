//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

typedef enum {
    WEAK,
    OK,
    STRONG
} strength_t;

int check_length(const char *password) {
    int length = strlen(password);
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

int check_complexity(const char *password) {
    int complexity = 0;
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= 'A' && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        } else {
            has_special_char = 1;
        }
    }

    if (has_lowercase + has_uppercase + has_digit + has_special_char >= 3) {
        complexity = 2;
    } else if (has_lowercase + has_uppercase + has_digit >= 2) {
        complexity = 1;
    }

    return complexity;
}

strength_t check_strength(const char *password) {
    int length_check = check_length(password);
    int complexity_check = check_complexity(password);

    if (length_check == 0 || complexity_check == 0) {
        return WEAK;
    } else if (complexity_check == 1) {
        return OK;
    } else {
        return STRONG;
    }
}

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    strength_t strength = check_strength(password);

    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case OK:
            printf("Your password is OK.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
    }

    return 0;
}