//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_char = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Determine the strength of the password
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (has_uppercase && has_lowercase) {
        strength++;
    }
    if (has_digit) {
        strength++;
    }
    if (has_special_char) {
        strength++;
    }

    return strength;
}

int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the result
    if (strength == 0) {
        printf("Your password is very weak.\n");
    } else if (strength == 1) {
        printf("Your password is weak.\n");
    } else if (strength == 2) {
        printf("Your password is moderate.\n");
    } else if (strength == 3) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is very strong.\n");
    }

    return 0;
}