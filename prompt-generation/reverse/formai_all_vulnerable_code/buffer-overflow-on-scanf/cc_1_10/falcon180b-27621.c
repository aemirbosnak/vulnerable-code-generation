//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define MIN_LOWER 1
#define MIN_UPPER 1
#define MIN_DIGIT 1
#define MIN_SYMBOL 1

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_symbol(char c) {
    return (!is_lower(c) &&!is_upper(c) &&!is_digit(c));
}

int count_lower(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_lower(password[i])) {
            count++;
        }
    }
    return count;
}

int count_upper(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_upper(password[i])) {
            count++;
        }
    }
    return count;
}

int count_digit(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_digit(password[i])) {
            count++;
        }
    }
    return count;
}

int count_symbol(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_symbol(password[i])) {
            count++;
        }
    }
    return count;
}

int count_unique_chars(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_lower(password[i]) || is_upper(password[i]) || is_digit(password[i]) || is_symbol(password[i])) {
            count++;
        }
    }
    return count;
}

int is_password_strong(char *password) {
    int lower = count_lower(password);
    int upper = count_upper(password);
    int digit = count_digit(password);
    int symbol = count_symbol(password);
    int unique_chars = count_unique_chars(password);

    if (strlen(password) < MIN_LENGTH) {
        return 0;
    } else if (lower < MIN_LOWER || upper < MIN_UPPER || digit < MIN_DIGIT || symbol < MIN_SYMBOL) {
        return 0;
    } else if (unique_chars < MIN_LENGTH / 2) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    if (is_password_strong(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}