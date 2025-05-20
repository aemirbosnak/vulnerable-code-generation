//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int is_special(char c) {
    return (c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

// Function to check if a password meets the required criteria
int check_password(char *password) {
    int length = strlen(password);
    int has_letter = 0;
    int has_digit = 0;
    int has_special = 0;

    // Check for at least one letter
    for (int i = 0; i < length; i++) {
        if (is_letter(password[i])) {
            has_letter = 1;
            break;
        }
    }

    // Check for at least one digit
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check for at least one special character
    for (int i = 0; i < length; i++) {
        if (is_special(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Check for minimum length
    if (length < 8) {
        return 0;
    }

    // Check for maximum length
    if (length > MAX_LENGTH) {
        return 0;
    }

    // Check for required criteria
    if (!has_letter ||!has_digit ||!has_special) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    if (check_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}