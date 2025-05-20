//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define the criteria for a strong password
#define MIN_LENGTH 8
#define MIN_ALPHA_UPPER 1
#define MIN_ALPHA_LOWER 1
#define MIN_NUMERIC 1
#define MIN_SPECIAL 1

// Function to check if the password meets the criteria
int check_password_strength(char *password) {
    int length = strlen(password);
    int alpha_upper = 0;
    int alpha_lower = 0;
    int numeric = 0;
    int special = 0;

    // Check the length of the password
    if (length < MIN_LENGTH) {
        return 0;
    }

    // Check for at least one uppercase alpha character
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            alpha_upper++;
            break;
        }
    }

    // Check for at least one lowercase alpha character
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            alpha_lower++;
            break;
        }
    }

    // Check for at least one numeric character
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            numeric++;
            break;
        }
    }

    // Check for at least one special character
    for (int i = 0; i < length; i++) {
        if (!((password[i] >= 'A' && password[i] <= 'Z') ||
              (password[i] >= 'a' && password[i] <= 'z') ||
              (password[i] >= '0' && password[i] <= '9'))) {
            special++;
            break;
        }
    }

    // Return 1 if all the criteria are met, 0 otherwise
    return (alpha_upper >= MIN_ALPHA_UPPER &&
            alpha_lower >= MIN_ALPHA_LOWER &&
            numeric >= MIN_NUMERIC &&
            special >= MIN_SPECIAL);
}

// Main function
int main() {
    char password[100];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the result
    if (strength) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak. Please try again.\n");
    }

    return 0;
}