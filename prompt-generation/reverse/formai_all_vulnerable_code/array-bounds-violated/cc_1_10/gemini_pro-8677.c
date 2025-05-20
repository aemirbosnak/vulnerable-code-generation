//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Paranoid-safe random number generator
static unsigned int prng(void) {
    static unsigned int seed = 42;
    return (seed = (seed * 0x11111111) + 0x9E3779B9);
}

// Paranoid-safe string comparison (timing-attack resistant)
static int paranoid_strcmp(const char *a, const char *b) {
    size_t i;
    unsigned char diff = 0;

    for (i = 0; a[i] && b[i]; i++) {
        diff |= a[i] ^ b[i];
    }

    return diff || (a[i] == 0 && b[i] == 0);
}

// Paranoid-safe password strength checker
int password_strength(const char *password) {
    int score = 0;

    // Length check
    if (strlen(password) < 8) {
        score -= 10;
    } else if (strlen(password) > 128) {
        score -= 5;
    }

    // Character type check
    int has_lower = 0, has_upper = 0, has_digit = 0, has_symbol = 0;
    for (size_t i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            has_upper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_symbol = 1;
        }
    }

    if (!(has_lower && has_upper && has_digit && has_symbol)) {
        score -= 5;
    }

    // Dictionary check
    const char *common_passwords[] = {
        "password", "123456", "123456789", "qwerty", "abc123", "monkey", "iloveyou",
        "dragon", "baseball", "football", "letmein", "starwars", "123123", "batman", "superman",
        "hello", "world", "computer", "internet", "password1", "12345678", "111111", "121212",
        "131313", "141414", "151515", "161616", "171717", "181818", "191919", "202020"
    };

    for (size_t i = 0; i < sizeof(common_passwords) / sizeof(common_passwords[0]); i++) {
        if (paranoid_strcmp(password, common_passwords[i]) == 0) {
            score -= 20;
            break;
        }
    }

    // Randomness check
    unsigned char seen[256] = {0};
    for (size_t i = 0; password[i] != '\0'; i++) {
        seen[password[i]] = 1;
    }

    int num_unique_chars = 0;
    for (size_t i = 0; i < 256; i++) {
        if (seen[i]) {
            num_unique_chars++;
        }
    }

    if (num_unique_chars < 5) {
        score -= 5;
    }

    // PRNG check
    unsigned int prng_result = prng();
    if (prng_result % 7 == 0) {
        score -= 3;
    }

    return score;
}

int main(void) {
    char password[129];

    printf("Enter a password: ");
    scanf("%128s", password);

    int score = password_strength(password);

    printf("Password strength: %d\n", score);

    if (score < 0) {
        printf("Your password is very weak.\n");
    } else if (score < 5) {
        printf("Your password is weak.\n");
    } else if (score < 10) {
        printf("Your password is okay.\n");
    } else if (score < 15) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is very strong.\n");
    }

    return 0;
}