//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8
#define PASSWORD_COMPLEXITY 4
#define PASSWORD_WEAKNESS 0.5

int main() {
    char password[PASSWORD_LENGTH + 1];
    int complexity = 0, weakness = 0;
    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", PASSWORD_LENGTH);
        return 1;
    }

    // Check complexity
    if (isalpha(password[0])) {
        has_uppercase = isupper(password[0]);
        has_lowercase = islower(password[0]);
    } else {
        has_number = 1;
    }

    for (int i = 1; i < strlen(password); i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (password[i] == '!'|| password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            has_special = 1;
        }
    }

    // Check for complexity
    if (has_uppercase && has_lowercase && has_number && has_special) {
        complexity = PASSWORD_COMPLEXITY;
    } else if (has_uppercase && has_lowercase && has_number) {
        complexity = 3;
    } else if (has_uppercase && has_lowercase && has_special) {
        complexity = 3;
    } else if (has_uppercase && has_number && has_special) {
        complexity = 3;
    } else if (has_lowercase && has_number && has_special) {
        complexity = 3;
    } else if (has_uppercase && has_lowercase) {
        complexity = 2;
    } else if (has_uppercase && has_number) {
        complexity = 2;
    } else if (has_lowercase && has_number) {
        complexity = 2;
    } else if (has_uppercase && has_special) {
        complexity = 2;
    } else if (has_lowercase && has_special) {
        complexity = 2;
    } else if (has_number && has_special) {
        complexity = 2;
    } else {
        complexity = 1;
    }

    // Calculate weakness
    if (complexity == PASSWORD_COMPLEXITY) {
        weakness = 1;
    } else {
        weakness = (float)complexity / PASSWORD_COMPLEXITY;
    }

    printf("Password strength: %d (out of %d)\n", complexity, PASSWORD_COMPLEXITY);
    printf("Password weakness: %.2f\n", weakness);

    return 0;
}