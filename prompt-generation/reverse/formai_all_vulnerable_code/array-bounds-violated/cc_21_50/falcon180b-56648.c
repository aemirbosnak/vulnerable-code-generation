//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length;

    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    length = strlen(password);

    // Remove newline character
    password[length - 1] = '\0';

    // Check for minimum length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A')) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a')) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for digit
    if (!strchr(password, '0')) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    // Check for special character
    if (!strchr(password, '!') &&!strchr(password, '@') &&!strchr(password, '#') &&
       !strchr(password, '$') &&!strchr(password, '%') &&!strchr(password, '&') &&
       !strchr(password, '*') &&!strchr(password, '?') &&!strchr(password, '/') &&
       !strchr(password, '^') &&!strchr(password, '&')) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Check for dictionary words
    char *dict[] = {"password", "admin", "123456", "qwerty", "letmein", "welcome", "monkey", "dragon", "sunshine", "iloveyou"};
    int dict_length = sizeof(dict) / sizeof(dict[0]);
    int i;
    for (i = 0; i < dict_length; i++) {
        if (!strcmp(password, dict[i])) {
            printf("Password must not be a dictionary word.\n");
            return 0;
        }
    }

    // Check for common patterns
    if (strstr(password, "123") || strstr(password, "qwe") || strstr(password, "asd")) {
        printf("Password must not contain common patterns.\n");
        return 0;
    }

    // Password is strong
    printf("Password is strong.\n");
    return 0;
}