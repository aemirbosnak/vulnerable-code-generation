//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
// Embark on a Cybersecurity Odyssey with Password Scrutiny

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Initialize an Array of Character Categories
char categories[] = {'A', 'a', '0', '!', '@'};

// Sentinel Values for Password Evaluation
int uppercase = 0, lowercase = 0, digit = 0, special = 0;
int min_length = 8, max_length = 64;

// Function to Validate Password Strength
bool password_strength(char *password) {
    // Determine the Length of the Password
    int length = strlen(password);

    // Reset Character Category Counts
    uppercase = lowercase = digit = special = 0;

    // Evaluate Each Character of the Password
    for (int i = 0; password[i] != '\0'; i++) {
        // Check for Uppercase Letters
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = 1;
            continue;
        }
        // Check for Lowercase Letters
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = 1;
            continue;
        }
        // Check for Digits
        if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
            continue;
        }
        // Check for Special Characters
        if (strchr(categories, password[i]) != NULL) {
            special = 1;
            continue;
        }
    }

    // Check if All Category Criteria are Met
    if (uppercase && lowercase && digit && special) {
        return true;
    }

    return false;
}

// Main Function to Test Password Strength
int main() {
    char password[max_length];

    // Prompt the User for a Password
    printf("Enter a Password: ");
    scanf("%s", password);

    // Analyze Password Strength
    if (password_strength(password)) {
        printf("Your Password is Strong!");
    } else {
        printf("Your Password is Weak.");
    }

    return 0;
}