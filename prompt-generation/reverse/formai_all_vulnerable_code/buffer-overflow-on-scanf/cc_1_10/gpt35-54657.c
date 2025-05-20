//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if a password is strong
int check_password_strength(char *password) {
    int len = strlen(password);

    // at least 8 characters long
    if (len < 8) {
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;

    // check each character in the password
    for (int i = 0; i < len; i++) {
        char c = password[i];

        // check if it's an uppercase letter
        if (isupper(c)) {
            has_uppercase = 1;
        }

        // check if it's a lowercase letter
        if (islower(c)) {
            has_lowercase = 1;
        }

        // check if it's a digit
        if (isdigit(c)) {
            has_digit = 1;
        }
    }

    // password must have at least one uppercase letter, one lowercase letter, and one digit
    if (!has_uppercase || !has_lowercase || !has_digit) {
        return 0;
    }

    // password meets all requirements
    return 1;
}

int main() {
    char password[100];

    printf("Enter a password: ");
    scanf("%s", password);

    if (check_password_strength(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak. Please make sure it is at least 8 characters long, and contains at least one uppercase letter, one lowercase letter, and one digit.\n");
    }

    return 0;
}