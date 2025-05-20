//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong enough
int check_password_strength(char *password) {
    int score = 0;

    // Check the length of the password
    if (strlen(password) < 8) {
        score += 1;
    }

    // Check if the password contains any lowercase letters
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        score += 1;
    }

    // Check if the password contains any uppercase letters
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        score += 1;
    }

    // Check if the password contains any digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        score += 1;
    }

    // Check if the password contains any special characters
    int has_special_character = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] < 'a' || password[i] > 'z' && password[i] < 'A' || password[i] > 'Z' && password[i] < '0' || password[i] > '9') {
            has_special_character = 1;
            break;
        }
    }
    if (!has_special_character) {
        score += 1;
    }

    // Return the score
    return score;
}

// Function to generate a random password
char *generate_random_password(int length) {
    char *password = malloc(length + 1);

    // Generate a random password
    for (int i = 0; i < length; i++) {
        password[i] = (rand() % 94) + 33;
    }

    // Terminate the string
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_random_password(length);

    // Check the strength of the password
    int score = check_password_strength(password);

    // Print the password and its strength
    printf("Password: %s\n", password);
    printf("Password strength: %d\n", score);

    // Free the memory allocated for the password
    free(password);

    return 0;
}