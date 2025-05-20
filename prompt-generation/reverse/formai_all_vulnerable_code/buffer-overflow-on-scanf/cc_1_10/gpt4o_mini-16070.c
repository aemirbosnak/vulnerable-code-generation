//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

// Function to check the length of the password
bool check_length(const char *password) {
    int len = strlen(password);
    return len >= MIN_LENGTH && len <= MAX_LENGTH;
}

// Function to check for uppercase letters
bool has_uppercase(const char *password) {
    while (*password) {
        if (isupper(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

// Function to check for lowercase letters
bool has_lowercase(const char *password) {
    while (*password) {
        if (islower(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

// Function to check for digits
bool has_digit(const char *password) {
    while (*password) {
        if (isdigit(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

// Function to check for special characters
bool has_special_char(const char *password) {
    const char *special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
    while (*password) {
        if (strchr(special_chars, *password)) {
            return true;
        }
        password++;
    }
    return false;
}

// Function to evaluate password strength
const char *evaluate_strength(const char *password) {
    int strength_score = 0;

    if (check_length(password)) strength_score++;
    if (has_uppercase(password)) strength_score++;
    if (has_lowercase(password)) strength_score++;
    if (has_digit(password)) strength_score++;
    if (has_special_char(password)) strength_score++;

    switch (strength_score) {
        case 0:
        case 1:
            return "Very Weak";
        case 2:
            return "Weak";
        case 3:
            return "Moderate";
        case 4:
            return "Strong";
        case 5:
            return "Very Strong";
        default:
            return "Unknown Strength";
    }
}

// Main function
int main() {
    char password[100];
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter a password to evaluate its strength:\n");

    // Read the password from the user
    scanf("%s", password);

    // Evaluate the password strength
    const char *strength = evaluate_strength(password);

    // Display the result
    printf("Your password strength is: %s\n", strength);

    // Provide feedback to the user
    if (strcmp(strength, "Very Weak") == 0) {
        printf("Tip: Use a more complex password with a mix of uppercase, lowercase, digits, and special characters.\n");
    } else if (strcmp(strength, "Weak") == 0) {
        printf("Tip: Try to increase the length and diversity of your password.\n");
    } else if (strcmp(strength, "Moderate") == 0) {
        printf("Tip: Good job! However, consider adding more special characters or length for better security.\n");
    } else if (strcmp(strength, "Strong") == 0) {
        printf("Tip: Great password! Just watch out for reusing it across different sites.\n");
    } else if (strcmp(strength, "Very Strong") == 0) {
        printf("Tip: Excellent! You have chosen a very strong password. Keep it safe!\n");
    }

    return 0;
}