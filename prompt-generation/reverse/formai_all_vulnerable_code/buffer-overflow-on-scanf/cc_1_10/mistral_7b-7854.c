//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_strong_password(char *password, int length) {
    bool has_digit = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_special = false;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = true;
        }
        if (isupper(password[i])) {
            has_upper = true;
        }
        if (islower(password[i])) {
            has_lower = true;
        }
        if (!isalnum(password[i])) {
            has_special = true;
        }

        if (has_digit && has_upper && has_lower && has_special) {
            return true;
        }
    }

    return false;
}

int main() {
    char password[101];
    int length;

    printf("Welcome to the Password Strength Analyzer 3000!\n");
    printf("Enter your password (max 100 characters): ");
    scanf("%s", password);
    length = strlen(password);

    if (length > 100) {
        printf("Error: Password too long!\n");
        return 1;
    }

    if (is_strong_password(password, length)) {
        printf("Ha Ha! Your password is stronger than a gorilla's!\n");
    } else {
        printf("Uh oh! Your password is weaker than a kitten's!\n");
    }

    return 0;
}