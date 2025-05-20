//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
/*
 * Password Strength Checker
 *
 * This program checks the strength of a password entered by the user and
 * provides feedback on its strength based on a set of criteria.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define PASSWORD_LENGTH_LIMIT 8

// Structure to hold the password and its strength
typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
} Password;

// Function to check the strength of the password
void check_password(Password *password) {
    // Check for password length
    if (strlen(password->password) < PASSWORD_LENGTH_LIMIT) {
        password->strength = 1;
    }

    // Check for number of digits
    int digit_count = 0;
    for (int i = 0; i < strlen(password->password); i++) {
        if (password->password[i] >= '0' && password->password[i] <= '9') {
            digit_count++;
        }
    }
    if (digit_count < 2) {
        password->strength++;
    }

    // Check for number of uppercase letters
    int uppercase_count = 0;
    for (int i = 0; i < strlen(password->password); i++) {
        if (password->password[i] >= 'A' && password->password[i] <= 'Z') {
            uppercase_count++;
        }
    }
    if (uppercase_count < 2) {
        password->strength++;
    }

    // Check for number of special characters
    int special_count = 0;
    for (int i = 0; i < strlen(password->password); i++) {
        if ((password->password[i] >= '!' && password->password[i] <= '/') ||
            (password->password[i] >= ':' && password->password[i] <= '@') ||
            (password->password[i] >= '[' && password->password[i] <= '`') ||
            (password->password[i] >= '{' && password->password[i] <= '~')) {
            special_count++;
        }
    }
    if (special_count < 2) {
        password->strength++;
    }
}

int main() {
    // Declare a variable to hold the password
    Password password;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    fgets(password.password, MAX_PASSWORD_LENGTH, stdin);

    // Check the strength of the password
    check_password(&password);

    // Print the strength of the password
    if (password.strength == 0) {
        printf("The password is very weak.\n");
    } else if (password.strength == 1) {
        printf("The password is weak.\n");
    } else if (password.strength == 2) {
        printf("The password is medium strength.\n");
    } else if (password.strength == 3) {
        printf("The password is strong.\n");
    } else {
        printf("The password is very strong.\n");
    }

    return 0;
}