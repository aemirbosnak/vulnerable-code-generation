//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
/*
* Password Strength Checker
*
* This program checks the strength of a given password.
*
* It checks the following:
* - Length of the password
* - Presence of special characters
* - Presence of numbers
* - Presence of uppercase letters
* - Presence of lowercase letters
*
* The password strength is determined by the number of checks that are passed.
* A password with all the checks passed is considered strong.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check the length of the password
bool check_length(char* password) {
    return strlen(password) >= 8;
}

// Function to check the presence of special characters
bool check_special_chars(char* password) {
    bool has_special_chars = false;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            has_special_chars = true;
            break;
        }
    }
    return has_special_chars;
}

// Function to check the presence of numbers
bool check_numbers(char* password) {
    bool has_numbers = false;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            has_numbers = true;
            break;
        }
    }
    return has_numbers;
}

// Function to check the presence of uppercase letters
bool check_uppercase_letters(char* password) {
    bool has_uppercase_letters = false;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase_letters = true;
            break;
        }
    }
    return has_uppercase_letters;
}

// Function to check the presence of lowercase letters
bool check_lowercase_letters(char* password) {
    bool has_lowercase_letters = false;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            has_lowercase_letters = true;
            break;
        }
    }
    return has_lowercase_letters;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);

    // Remove the newline character from the end of the string
    password[strlen(password) - 1] = '\0';

    // Check the password strength
    int password_strength = 0;
    if (check_length(password)) {
        password_strength++;
    }
    if (check_special_chars(password)) {
        password_strength++;
    }
    if (check_numbers(password)) {
        password_strength++;
    }
    if (check_uppercase_letters(password)) {
        password_strength++;
    }
    if (check_lowercase_letters(password)) {
        password_strength++;
    }

    // Print the password strength
    switch (password_strength) {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderately strong.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
        default:
            printf("Your password is extremely strong.\n");
            break;
    }

    return 0;
}