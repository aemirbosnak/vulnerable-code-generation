//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PW_LEN 8
#define MAX_PW_LEN 64

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *password = argv[1];
    int len = strlen(password);

    if (len < MIN_PW_LEN) {
        printf("Password too short\n");
        return EXIT_FAILURE;
    } else if (len > MAX_PW_LEN) {
        printf("Password too long\n");
        return EXIT_FAILURE;
    }

    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < len; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            has_upper = 1;
        } else if (c >= 'a' && c <= 'z') {
            has_lower = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    if (!has_upper) {
        printf("Password must contain at least one uppercase letter\n");
        return EXIT_FAILURE;
    }

    if (!has_lower) {
        printf("Password must contain at least one lowercase letter\n");
        return EXIT_FAILURE;
    }

    if (!has_digit) {
        printf("Password must contain at least one digit\n");
        return EXIT_FAILURE;
    }

    if (!has_special) {
        printf("Password must contain at least one special character\n");
        return EXIT_FAILURE;
    }

    printf("Password is strong\n");
    return EXIT_SUCCESS;
}