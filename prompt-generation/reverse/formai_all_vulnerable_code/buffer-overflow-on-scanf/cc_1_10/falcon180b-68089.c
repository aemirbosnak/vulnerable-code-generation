//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8

int isPasswordStrong(char *password) {
    // Check if the password is at least 8 characters long
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        printf("Password should be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 0;
    }

    // Check for uppercase letters
    if (!isupper(password[0])) {
        printf("Password should start with an uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letters
    if (!islower(password[1])) {
        printf("Password should contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for digits
    if (!isdigit(password[2])) {
        printf("Password should contain at least one digit.\n");
        return 0;
    }

    // Check for special characters
    if (!isalpha(password[3])) {
        printf("Password should contain at least one special character (!@#$%^&*).\n");
        return 0;
    }

    // Check for consecutive characters
    if (password[0] == password[1]) {
        printf("Password should not contain consecutive characters.\n");
        return 0;
    }

    return 1;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordStrong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}