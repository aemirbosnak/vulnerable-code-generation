//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

int main(int argc, char *argv[]) {
    char password[MAX_LENGTH + 1];

    // Get the password from the user.
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password.
    if (strlen(password) < MIN_LENGTH) {
        printf("Password is too short. Must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    // Check if the password contains any uppercase letters.
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    // Check if the password contains any lowercase letters.
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    // Check if the password contains any digits.
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    // Check if the password contains any special characters.
    int has_special = 0;
    char special_characters[] = "!@#$%^&*()_-=+?";
    for (int i = 0; i < strlen(password); i++) {
        for (int j = 0; j < strlen(special_characters); j++) {
            if (password[i] == special_characters[j]) {
                has_special = 1;
                break;
            }
        }
    }

    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    // The password is strong enough.
    printf("Password is strong.\n");
    return 0;
}