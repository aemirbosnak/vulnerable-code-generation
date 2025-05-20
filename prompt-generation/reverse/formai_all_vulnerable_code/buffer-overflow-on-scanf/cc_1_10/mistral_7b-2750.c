//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define WEAK_POINTS_COUNT 3

typedef enum { LENGTH, COMPLEXITY, PATTERNS } CHECK_TYPE;

int password_length(const char *password);
int password_complexity(const char *password);
int check_weak_points(const char *password);
int check_password_strength(const char *password);
void print_password_strength(int strength);

int main(void) {
    char input_password[1024];

    printf("Enter your password: ");
    scanf("%s", input_password);

    int password_strength = check_password_strength(input_password);
    print_password_strength(password_strength);

    return 0;
}

int password_length(const char *password) {
    size_t password_len = strlen(password);
    return password_len >= MIN_LENGTH ? 1 : 0;
}

int password_complexity(const char *password) {
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_char_count = 0;

    for (size_t i = 0; password[i] != '\0'; ++i) {
        if (isupper(password[i])) {
            ++uppercase_count;
        } else if (islower(password[i])) {
            ++lowercase_count;
        } else if (isdigit(password[i])) {
            ++digit_count;
        } else {
            ++special_char_count;
        }
    }

    int complexity = 0;
    if (uppercase_count > 0) ++complexity;
    if (lowercase_count > 0) ++complexity;
    if (digit_count > 0) ++complexity;
    if (special_char_count > 0) ++complexity;

    return complexity >= 2 ? 1 : 0;
}

int check_weak_points(const char *password) {
    int weak_points_count = 0;

    const char *weak_points[] = {
        "password",
        "qwerty",
        "123456",
        "12345678",
        "123456789",
        "1234567890"
    };

    for (size_t i = 0; i < sizeof(weak_points) / sizeof(weak_points[0]); ++i) {
        size_t weak_point_len = strlen(weak_points[i]);
        if (strncmp(password, weak_points[i], weak_point_len) == 0) {
            ++weak_points_count;
            break;
        }
    }

    return weak_points_count < WEAK_POINTS_COUNT ? 1 : 0;
}

int check_password_strength(const char *password) {
    int strength = 0;

    strength += password_length(password) ? 1 : 0;
    strength += password_complexity(password) ? 1 : 0;
    strength += check_weak_points(password) ? 1 : 0;

    return strength >= 3 ? 1 : 0;
}

void print_password_strength(int strength) {
    if (strength) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }
}