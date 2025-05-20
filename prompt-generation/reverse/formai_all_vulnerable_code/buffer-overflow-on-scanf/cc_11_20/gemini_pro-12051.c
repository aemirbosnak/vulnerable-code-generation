//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Colors for output
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

// Minimum password length
#define MIN_LENGTH 8

// Maximum password length
#define MAX_LENGTH 64

// Array of symbols to check for
char symbols[] = "!@#$%^&*()-_=+";

// Function to check if a password is strong
int check_password(char *password) {
    int score = 0;

    // Check the length of the password
    if (strlen(password) < MIN_LENGTH) {
        printf(RED "Password too short. Minimum length is %d characters.\n" RESET, MIN_LENGTH);
    } else if (strlen(password) > MAX_LENGTH) {
        printf(RED "Password too long. Maximum length is %d characters.\n" RESET, MAX_LENGTH);
    } else {
        score++;
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
        printf(YELLOW "Password should contain at least one uppercase letter.\n" RESET);
    } else {
        score++;
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
        printf(YELLOW "Password should contain at least one lowercase letter.\n" RESET);
    } else {
        score++;
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
        printf(YELLOW "Password should contain at least one digit.\n" RESET);
    } else {
        score++;
    }

    // Check if the password contains at least one symbol
    int has_symbol = 0;
    for (int i = 0; i < strlen(password); i++) {
        for (int j = 0; j < strlen(symbols); j++) {
            if (password[i] == symbols[j]) {
                has_symbol = 1;
                break;
            }
        }
    }
    if (!has_symbol) {
        printf(YELLOW "Password should contain at least one symbol (%s).\n" RESET, symbols);
    } else {
        score++;
    }

    // Return the score
    return score;
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int score = check_password(password);

    // Print the score
    printf("Password strength: ");
    switch (score) {
        case 0:
            printf(RED "Very weak\n" RESET);
            break;
        case 1:
            printf(RED "Weak\n" RESET);
            break;
        case 2:
            printf(YELLOW "Fair\n" RESET);
            break;
        case 3:
            printf(GREEN "Good\n" RESET);
            break;
        case 4:
            printf(GREEN "Strong\n" RESET);
            break;
        case 5:
            printf(GREEN "Very strong\n" RESET);
            break;
    }

    return 0;
}