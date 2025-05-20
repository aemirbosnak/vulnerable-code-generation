//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MIN_DIGITS 2
#define MIN_UPPER 2
#define MIN_LOWER 2
#define MIN_SPECIAL 1

int main() {
    char password[128];
    int digits = 0, upper = 0, lower = 0, special = 0;
    int length = 0, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; password[i] != '\0'; ++i) {
        if (isdigit(password[i])) {
            ++digits;
        }

        if (isupper(password[i])) {
            ++upper;
        }

        if (islower(password[i])) {
            ++lower;
        }

        if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?`~", password[i])) {
            ++special;
        }
    }

    strength = length * (digits / MIN_DIGITS) *
               (upper / MIN_UPPER) *
               (lower / MIN_LOWER) *
               (special / MIN_SPECIAL);

    printf("Password length: %d\n", length);
    printf("Digits: %d / %d\n", digits, MIN_DIGITS);
    printf("Uppercase: %d / %d\n", upper, MIN_UPPER);
    printf("Lowercase: %d / %d\n", lower, MIN_LOWER);
    printf("Special characters: %d / %d\n", special, MIN_SPECIAL);
    printf("Password strength: %d\n", strength);

    if (strength >= (length * 4)) {
        printf("Strong\n");
    } else if (strength >= (length * 3)) {
        printf("Moderate\n");
    } else {
        printf("Weak\n");
    }

    return 0;
}