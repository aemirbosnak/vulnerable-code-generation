//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PASSWORD_LENGTH_MIN 8
#define PASSWORD_LENGTH_MAX 64
#define PASSWORD_SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>/?`~"

bool is_special_char(char c) {
    for (int i = 0; i < strlen(PASSWORD_SPECIAL_CHARS); i++) {
        if (c == PASSWORD_SPECIAL_CHARS[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    char password[PASSWORD_LENGTH_MAX];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    if (length < PASSWORD_LENGTH_MIN || length > PASSWORD_LENGTH_MAX) {
        printf("Password length must be between %d and %d characters.\n", PASSWORD_LENGTH_MIN, PASSWORD_LENGTH_MAX);
        return 1;
    }

    int num_uppercase = 0;
    int num_lowercase = 0;
    int num_digits = 0;
    int num_special_chars = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                num_uppercase++;
            } else {
                num_lowercase++;
            }
        } else if (isdigit(c)) {
            num_digits++;
        } else if (is_special_char(c)) {
            num_special_chars++;
        }
    }

    int total_strength = 0;
    total_strength += num_uppercase * 2;
    total_strength += num_lowercase * 2;
    total_strength += num_digits * 3;
    total_strength += num_special_chars * 4;

    if (total_strength < 16) {
        printf("Weak password. Please choose a stronger one.\n");
    } else if (total_strength < 32) {
        printf("Moderate password. Keep it secret, keep it safe.\n");
    } else {
        printf("Strong password. You're a real wizard with those passwords!\n");
    }

    return 0;
}