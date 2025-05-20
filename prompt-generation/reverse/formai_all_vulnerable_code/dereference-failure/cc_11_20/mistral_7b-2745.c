//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK 0
#define LOW 1
#define MEDIUM 2
#define STRONG 3
#define VERY_STRONG 4

int check_password_strength(const char *password) {
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_char_count = 0;

    if (length < MIN_LENGTH) {
        return WEAK;
    }

    for (int i = 0; password[i]; ++i) {
        if (isdigit(password[i])) {
            ++digit_count;
        } else if (isalpha(password[i])) {
            if (isupper(password[i])) {
                ++uppercase_count;
            } else {
                ++lowercase_count;
            }
        } else {
            ++special_char_count;
        }
    }

    if (uppercase_count > 0 && lowercase_count > 0 && digit_count > 0 && special_char_count > 0) {
        return VERY_STRONG;
    }

    if (uppercase_count > 0 && lowercase_count > 0 && digit_count > 0) {
        return STRONG;
    }

    if (uppercase_count > 0 || lowercase_count > 0 || digit_count > 0 || special_char_count > 0) {
        return MEDIUM;
    }

    return LOW;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    int strength = check_password_strength(argv[1]);

    switch (strength) {
        case WEAK:
            printf("The password is weak.\n");
            break;
        case LOW:
            printf("The password is low.\n");
            break;
        case MEDIUM:
            printf("The password is medium.\n");
            break;
        case STRONG:
            printf("The password is strong.\n");
            break;
        case VERY_STRONG:
            printf("The password is very strong.\n");
            break;
        default:
            printf("Unexpected password strength level: %d\n", strength);
            break;
    }

    return 0;
}