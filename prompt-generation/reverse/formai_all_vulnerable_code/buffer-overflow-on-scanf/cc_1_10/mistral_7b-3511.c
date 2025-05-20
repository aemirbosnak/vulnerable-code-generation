//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_LEN 8
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

bool check_password_strength(const char *password) {
    size_t len = strlen(password);
    int num_digits = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;
    int num_special_chars = 0;

    if (len < MIN_LEN) return WEAK;

    for (size_t i = 0; i < len; i++) {
        if (isdigit(password[i])) num_digits++;
        if (isupper(password[i])) num_uppercase++;
        if (islower(password[i])) num_lowercase++;
        if (!isalnum(password[i])) num_special_chars++;
    }

    bool has_digits = num_digits > 0;
    bool has_uppercase = num_uppercase > 0;
    bool has_lowercase = num_lowercase > 0;
    bool has_special_chars = num_special_chars > 0;

    if (has_digits && has_uppercase && has_lowercase && has_special_chars)
        return STRONG;

    if (has_digits || has_uppercase || has_lowercase)
        return MEDIUM;

    return WEAK;
}

int main() {
    char password[100];
    int strength;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    switch (strength) {
        case WEAK:
            printf("Your password is weak. Please consider adding digits, uppercase letters, lowercase letters and special characters.\n");
            break;
        case MEDIUM:
            printf("Your password is medium. You might want to add some special characters to make it stronger.\n");
            break;
        case STRONG:
            printf("Your password is strong! Keep it up!\n");
            break;
    }

    return 0;
}