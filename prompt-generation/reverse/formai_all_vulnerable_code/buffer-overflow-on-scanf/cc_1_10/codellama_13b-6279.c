//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8
#define PASSWORD_STRENGTH_THRESHOLD 5

int check_password_strength(char *password) {
    int length = strlen(password);
    if (length < PASSWORD_LENGTH) {
        return 0;
    }

    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (islower(c)) {
            has_lower = 1;
        } else if (isupper(c)) {
            has_upper = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (ispunct(c)) {
            has_special = 1;
        }
    }

    int strength = 0;
    if (has_lower) {
        strength++;
    }
    if (has_upper) {
        strength++;
    }
    if (has_digit) {
        strength++;
    }
    if (has_special) {
        strength++;
    }

    return strength;
}

int main() {
    char password[PASSWORD_LENGTH + 1];
    printf("Enter password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);
    if (strength >= PASSWORD_STRENGTH_THRESHOLD) {
        printf("Strong password!\n");
    } else {
        printf("Weak password!\n");
    }

    return 0;
}