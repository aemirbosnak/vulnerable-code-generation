//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a lowercase letter
int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a special character
int is_special(char c) {
    return (!is_digit(c) && !is_lowercase(c) && !is_uppercase(c));
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) < 8) {
        strength++;
    } else if (strlen(password) >= 8 && strlen(password) <= 12) {
        strength += 2;
    } else {
        strength += 3;
    }

    // Check the variety of characters in the password
    int variety = 0;
    if (is_digit(password[0])) {
        variety++;
    }
    if (is_lowercase(password[0])) {
        variety++;
    }
    if (is_uppercase(password[0])) {
        variety++;
    }
    if (is_special(password[0])) {
        variety++;
    }
    for (int i = 1; i < strlen(password); i++) {
        if (is_digit(password[i]) && !is_digit(password[i - 1])) {
            variety++;
        }
        if (is_lowercase(password[i]) && !is_lowercase(password[i - 1])) {
            variety++;
        }
        if (is_uppercase(password[i]) && !is_uppercase(password[i - 1])) {
            variety++;
        }
        if (is_special(password[i]) && !is_special(password[i - 1])) {
            variety++;
        }
    }
    strength += variety;

    // Check if the password contains any common words
    char *common_words[] = {"password", "123456", "qwerty", "iloveyou", "admin", "test", "secret"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(password, common_words[i]) == 0) {
            strength--;
        }
    }

    // Return the strength of the password
    return strength;
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the strength of the password
    printf("The strength of your password is: %d\n", strength);

    return 0;
}