//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    // check password length
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 0;
    } else if (length > MAX_PASSWORD_LENGTH) {
        printf("Password must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
        return 0;
    }

    // check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
            break;
        }
    }

    // check for symbols
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            symbols = 1;
            break;
        }
    }

    // check for complexity
    if (uppercase && lowercase && numbers && symbols) {
        printf("Password is strong.\n");
        return 1;
    } else {
        printf("Password is weak.\n");
        return 0;
    }
}

int main() {
    char password[64];
    printf("Enter your password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}