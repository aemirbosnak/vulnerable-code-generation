//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64

int is_password_strong(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    if (is_password_strong(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

int is_password_strong(char *password) {
    // Check if password contains at least one uppercase letter
    char *uppercase_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *found_uppercase_letter = strchr(password, *uppercase_letter);

    if (found_uppercase_letter == NULL) {
        return 0;
    }

    // Check if password contains at least one lowercase letter
    char *lowercase_letter = "abcdefghijklmnopqrstuvwxyz";
    char *found_lowercase_letter = strchr(password, *lowercase_letter);

    if (found_lowercase_letter == NULL) {
        return 0;
    }

    // Check if password contains at least one digit
    char *digit = "0123456789";
    char *found_digit = strchr(password, *digit);

    if (found_digit == NULL) {
        return 0;
    }

    // Check if password contains at least one special character
    char *special_chars = "!@#$%^&*()_+-=[]{}\\|;':\",.<>/?";
    char *found_special_char = strchr(password, *special_chars);

    if (found_special_char == NULL) {
        return 0;
    }

    // Check if password is at least 8 characters long
    if (strlen(password) < 8) {
        return 0;
    }

    return 1;
}