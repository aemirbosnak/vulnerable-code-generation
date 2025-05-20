//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_LENGTH 8
#define MIN_DIGITS 2
#define MIN_SPECIAL_CHAR 1

typedef struct {
    int length;
    int digits;
    int special_chars;
} password_stats;

void print_password_stats(password_stats stats) {
    printf("\nPassword Stats:\n");
    printf("Length: %d\n", stats.length);
    printf("Digits: %d\n", stats.digits);
    printf("Special Characters: %d\n", stats.special_chars);
}

bool is_digit(char c) {
    return isdigit(c);
}

bool is_special_char(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' ||
            c == '%' || c == '^' || c == '&' || c == '*' ||
            c == '(' || c == ')' || c == '-' || c == '+' ||
            c == '=' || c == '{' || c == '}' || c == '[' ||
            c == ']' || c == '|' || c == '\\' || c == ';' ||
            c == ':' || c == '<' || c == '>' || c == ',');
}

bool check_password_strength(char *password) {
    password_stats stats = {0};
    int length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return false;
    }

    for (int i = 0; password[i]; i++) {
        if (is_digit(password[i])) {
            stats.digits++;
        } else if (is_special_char(password[i])) {
            stats.special_chars++;
        }
    }

    stats.length = length;

    print_password_stats(stats);

    if (stats.digits < MIN_DIGITS || stats.special_chars < MIN_SPECIAL_CHAR) {
        printf("Password must contain at least %d digits and %d special characters.\n", MIN_DIGITS, MIN_SPECIAL_CHAR);
        return false;
    }

    printf("Password is strong.\n");
    return true;
}

int main() {
    char password[MIN_LENGTH + 1];
    int choice;

    do {
        printf("\nPassword Strength Checker\n");
        printf("Enter a password to check its strength (minimum length: %d): ", MIN_LENGTH);
        scanf("%s", password);

        check_password_strength(password);

        printf("\nDo you want to check another password? (1: Yes, 0: No)\n");
        scanf("%d", &choice);
    } while (choice != 0);

    return 0;
}