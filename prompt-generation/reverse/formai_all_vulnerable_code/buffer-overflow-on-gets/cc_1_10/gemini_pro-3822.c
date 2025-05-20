//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 128

// Check if the password is long enough
int check_length(char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        return 0;
    }
    if (length > MAX_LENGTH) {
        return 0;
    }
    return 1;
}

// Check if the password contains a digit
int check_digit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains a lowercase letter
int check_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains an uppercase letter
int check_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains a special character
int check_special(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Calculate the password score
int calculate_score(char *password) {
    int score = 0;

    if (check_length(password)) {
        score += 1;
    }
    if (check_digit(password)) {
        score += 1;
    }
    if (check_lowercase(password)) {
        score += 1;
    }
    if (check_uppercase(password)) {
        score += 1;
    }
    if (check_special(password)) {
        score += 1;
    }

    return score;
}

// Print the password strength
void print_strength(int score) {
    switch (score) {
        case 0:
        case 1:
            printf("Weak");
            break;
        case 2:
        case 3:
            printf("Moderate");
            break;
        case 4:
        case 5:
            printf("Strong");
            break;
        default:
            printf("Invalid");
            break;
    }
}

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter your password: ");
    gets(password);

    int score = calculate_score(password);

    printf("Your password strength is: ");
    print_strength(score);

    return 0;
}