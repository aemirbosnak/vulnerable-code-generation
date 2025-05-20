//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
/*
 * Unique C Password Strength Checker Example Program in a Multiplayer Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the password strength levels
enum password_strength {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
};

// Define the password requirements
enum password_requirements {
    LENGTH,
    UPPERCASE,
    LOWERCASE,
    DIGIT,
    SPECIAL
};

// Define the password structure
struct password {
    char* value;
    enum password_strength strength;
    enum password_requirements requirements;
};

// Define the password checker function
bool check_password(struct password* password) {
    // Check if the password is long enough
    if (strlen(password->value) < 8) {
        password->strength = WEAK;
        return false;
    }

    // Check if the password contains uppercase and lowercase characters
    bool has_uppercase = false;
    bool has_lowercase = false;
    for (int i = 0; i < strlen(password->value); i++) {
        if (isupper(password->value[i])) {
            has_uppercase = true;
        } else if (islower(password->value[i])) {
            has_lowercase = true;
        }
    }
    if (!has_uppercase || !has_lowercase) {
        password->strength = WEAK;
        return false;
    }

    // Check if the password contains a digit
    bool has_digit = false;
    for (int i = 0; i < strlen(password->value); i++) {
        if (isdigit(password->value[i])) {
            has_digit = true;
            break;
        }
    }
    if (!has_digit) {
        password->strength = WEAK;
        return false;
    }

    // Check if the password contains a special character
    bool has_special = false;
    for (int i = 0; i < strlen(password->value); i++) {
        if (!isalnum(password->value[i])) {
            has_special = true;
            break;
        }
    }
    if (!has_special) {
        password->strength = WEAK;
        return false;
    }

    // Check if the password meets all the requirements
    if (has_uppercase && has_lowercase && has_digit && has_special) {
        password->strength = VERY_STRONG;
        return true;
    } else if (has_uppercase && has_lowercase && has_digit) {
        password->strength = STRONG;
        return true;
    } else if (has_uppercase && has_lowercase && has_special) {
        password->strength = MEDIUM;
        return true;
    } else {
        password->strength = WEAK;
        return false;
    }
}

// Define the main function
int main() {
    // Get the password from the user
    struct password password;
    printf("Enter a password: ");
    scanf("%s", password.value);

    // Check the password strength
    if (check_password(&password)) {
        printf("Password strength: %s\n", password.strength == VERY_STRONG ? "Very Strong" : password.strength == STRONG ? "Strong" : password.strength == MEDIUM ? "Medium" : "Weak");
    } else {
        printf("Password is not strong enough.\n");
    }

    return 0;
}