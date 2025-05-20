//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

// Function to check if the password is strong
int check_password_strength(char *password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) < MIN_LENGTH) {
        printf("Password is too short. It should be at least %d characters long.\n", MIN_LENGTH);
        return strength;
    } else if (strlen(password) > MAX_LENGTH) {
        printf("Password is too long. It should be at most %d characters long.\n", MAX_LENGTH);
        return strength;
    }

    // Check for uppercase letters
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        printf("Password should contain at least one uppercase letter.\n");
        return strength;
    }

    // Check for lowercase letters
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        printf("Password should contain at least one lowercase letter.\n");
        return strength;
    }

    // Check for digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        printf("Password should contain at least one digit.\n");
        return strength;
    }

    // Check for special characters
    int has_special_character = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            has_special_character = 1;
            break;
        }
    }
    if (!has_special_character) {
        printf("Password should contain at least one special character (!, @, #, $, %%).\n");
        return strength;
    }

    // Increment the strength for each criteria met
    strength++;
    if (has_uppercase) strength++;
    if (has_lowercase) strength++;
    if (has_digit) strength++;
    if (has_special_character) strength++;

    return strength;
}

int main() {
    // Get the password from the user
    char password[MAX_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the strength of the password
    switch (strength) {
        case 0:
            printf("Password is weak.\n");
            break;
        case 1:
            printf("Password is fair.\n");
            break;
        case 2:
            printf("Password is good.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
        case 5:
            printf("Password is excellent.\n");
            break;
        default:
            printf("Password strength could not be determined.\n");
    }

    return 0;
}