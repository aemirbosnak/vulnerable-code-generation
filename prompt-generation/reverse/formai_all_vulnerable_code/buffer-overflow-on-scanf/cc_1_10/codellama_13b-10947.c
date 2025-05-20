//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
// Expert-level C Password Strength Checker example program

#include <stdio.h>
#include <string.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 16

int is_valid_password(const char *password) {
    // Check if password is at least 8 characters long
    if (strlen(password) < PASSWORD_MIN_LENGTH) {
        return 0;
    }

    // Check if password is at most 16 characters long
    if (strlen(password) > PASSWORD_MAX_LENGTH) {
        return 0;
    }

    // Check if password contains at least one letter and one number
    if (!strpbrk(password, "0123456789") || !strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
        return 0;
    }

    // Check if password contains at least one special character
    if (!strpbrk(password, "!@#$%^&*()_+-=[]{}|;:<>,./?")) {
        return 0;
    }

    // Check if password does not contain any spaces
    if (strchr(password, ' ')) {
        return 0;
    }

    return 1;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Valid password!\n");
    } else {
        printf("Invalid password!\n");
    }

    return 0;
}