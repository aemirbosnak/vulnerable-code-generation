//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

typedef enum { UPPERCASE, LOWERCASE, NUMBER, SPECIAL_CHAR, LENGTH, NUM_TYPES } CheckType;

const char *special_chars = "!@#$%^&*()_+{}|:<>?";

static bool check_password(const char *password, size_t length) {
    bool result = true;
    size_t num_upper = 0, num_lower = 0, num_digit = 0, num_special = 0;

    for (size_t i = 0; i < length; ++i) {
        if (isdigit(password[i])) {
            ++num_digit;
        } else if (isupper(password[i])) {
            ++num_upper;
        } else if (islower(password[i])) {
            ++num_lower;
        } else if (strchr(special_chars, password[i])) {
            ++num_special;
        }

        if (!result && (length - i > 1)) {
            break;
        }
    }

    if (length < MIN_LENGTH) {
        result = false;
    } else if (num_upper == 0 || num_lower == 0 || num_digit == 0) {
        result = false;
    } else {
        result = (num_special > 0);
    }

    return result;
}

int main(void) {
    char password[MAX_LENGTH + 1];
    size_t length;

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);

    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }

    if (check_password(password, length)) {
        printf("Strong password!\n");
    } else {
        printf("Weak password. Try to include at least one uppercase letter,\n");
        printf("one lowercase letter, one digit, and one special character.\n");
    }

    return EXIT_SUCCESS;
}