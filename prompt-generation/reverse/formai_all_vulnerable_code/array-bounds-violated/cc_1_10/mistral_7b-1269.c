//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MIN_DIGITS 2
#define MIN_UPPER 2
#define MIN_LOWER 2
#define MIN_SPECIAL 1

bool is_digit(char c) {
    return (isdigit(c) != 0);
}

bool is_upper(char c) {
    return (isupper(c) != 0);
}

bool is_lower(char c) {
    return (islower(c) != 0);
}

bool is_special(char c) {
    const char special[] = { '!', '*', '#', '%', '&', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ';', ':', '\"', '\'', '<', '>', '.', ',' };
    size_t i;

    for (i = 0; i < sizeof(special) / sizeof(special[0]); ++i) {
        if (special[i] == c) {
            return true;
        }
    }

    return false;
}

size_t password_strength(const char *password) {
    size_t length = strlen(password);
    size_t digits = 0, upper = 0, lower = 0, special = 0;

    for (size_t i = 0; i < length; ++i) {
        if (is_digit(password[i])) {
            ++digits;
        }
        if (is_upper(password[i])) {
            ++upper;
        }
        if (is_lower(password[i])) {
            ++lower;
        }
        if (is_special(password[i])) {
            ++special;
        }
    }

    size_t strength = length;

    strength -= (MIN_LENGTH > length ? length : MIN_LENGTH);

    strength += (digits >= MIN_DIGITS ? 0 : MIN_DIGITS - digits);
    strength += (upper >= MIN_UPPER ? 0 : MIN_UPPER - upper);
    strength += (lower >= MIN_LOWER ? 0 : MIN_LOWER - lower);
    strength += (special >= MIN_SPECIAL ? 0 : MIN_SPECIAL - special);

    return strength;
}

void print_strength(size_t strength) {
    const char *strength_names[] = { "Very Weak", "Weak", "Moderate", "Strong", "Very Strong" };

    printf("Password strength: %s\n", strength_names[strength]);
}

int main() {
    char password[128];

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    size_t strength = password_strength(password);
    print_strength(strength);

    return EXIT_SUCCESS;
}