//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
/*
 * Password Strength Checker
 *
 * A simple program to check the strength of a given password.
 *
 * Usage: ./password_strength <password>
 *
 * Output:
 *   0 - weak
 *   1 - medium
 *   2 - strong
 *
 */
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 16

int check_password(char *password) {
    // Check if the password is empty
    if (strlen(password) == 0) {
        return 0;
    }

    // Check if the password is too long
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    // Check if the password contains at least one digit
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        return 0;
    }

    // Check if the password contains at least one uppercase letter
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        return 0;
    }

    // Check if the password contains at least one lowercase letter
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        return 0;
    }

    // Check if the password contains at least one special character
    int has_special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~')) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        return 0;
    }

    // Check if the password contains at least 8 characters
    if (strlen(password) < 8) {
        return 1;
    }

    // Check if the password contains at least 12 characters
    if (strlen(password) < 12) {
        return 2;
    }

    // If all the conditions are met, return 3
    return 3;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./password_strength <password>\n");
        return 1;
    }

    char *password = argv[1];
    int strength = check_password(password);

    switch (strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Medium\n");
            break;
        case 2:
            printf("Strong\n");
            break;
        case 3:
            printf("Very Strong\n");
            break;
        default:
            printf("Invalid password\n");
            break;
    }

    return 0;
}