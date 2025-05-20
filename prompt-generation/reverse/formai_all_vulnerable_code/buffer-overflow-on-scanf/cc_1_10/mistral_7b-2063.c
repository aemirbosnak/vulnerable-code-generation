//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MIN_NUM_DIGITS 2
#define MIN_NUM_SPECIAL_CHARS 2
#define MAX_NUM_SPECIAL_CHARS 4
#define MIN_UPPERCASE 2
#define MIN_LOWERCASE 2

bool is_valid_password(const char *password) {
    size_t length = strlen(password);
    if (length < MIN_LENGTH) {
        return false;
    }

    int num_digits = 0;
    int num_special_chars = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;

    for (size_t i = 0; password[i] != '\0'; ++i) {
        if (isdigit(password[i])) {
            ++num_digits;
        } else if (isalpha(password[i])) {
            if (isupper(password[i])) {
                ++num_uppercase;
            } else {
                ++num_lowercase;
            }
        } else {
            if (num_special_chars < MAX_NUM_SPECIAL_CHARS) {
                ++num_special_chars;
            }
        }
    }

    return num_digits >= MIN_NUM_DIGITS &&
           num_special_chars >= MIN_NUM_SPECIAL_CHARS &&
           num_uppercase >= MIN_UPPERCASE &&
           num_lowercase >= MIN_LOWERCASE;
}

int main() {
    char password[128];
    bool is_valid = false;

    printf("Enter your password: ");
    scanf("%s", password);

    is_valid = is_valid_password(password);

    if (is_valid) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
        printf("Minimum requirements: %d digits, %d special characters,\n", MIN_NUM_DIGITS, MIN_NUM_SPECIAL_CHARS);
        printf("%d uppercase letters, %d lowercase letters.\n", MIN_UPPERCASE, MIN_LOWERCASE);
    }

    return 0;
}