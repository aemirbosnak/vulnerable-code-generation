//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    int length = strlen(password);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password must be between %d and %d characters long.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_symbol = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            has_uppercase = 1;
        } else if (islower(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_symbol = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    if (!has_symbol) {
        printf("Password must contain at least one symbol (!@#$%^&*).\n");
        return 1;
    }

    printf("Password is strong!\n");
    return 0;
}