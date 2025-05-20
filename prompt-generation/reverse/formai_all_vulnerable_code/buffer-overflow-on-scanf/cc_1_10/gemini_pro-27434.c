//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

typedef enum {
    WEAK,
    MEDIUM,
    STRONG
} Strength;

Strength check_password(const char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return WEAK;
    }

    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (islower(c)) {
            has_lowercase = 1;
        } else if (isupper(c)) {
            has_uppercase = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    int num_requirements = has_lowercase + has_uppercase + has_digit + has_special;

    if (num_requirements < 3) {
        return WEAK;
    } else if (num_requirements == 3) {
        return MEDIUM;
    } else {
        return STRONG;
    }
}

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    Strength strength = check_password(password);

    switch (strength) {
        case WEAK:
            printf("The password is weak.\n");
            break;
        case MEDIUM:
            printf("The password is medium.\n");
            break;
        case STRONG:
            printf("The password is strong.\n");
            break;
    }

    return 0;
}