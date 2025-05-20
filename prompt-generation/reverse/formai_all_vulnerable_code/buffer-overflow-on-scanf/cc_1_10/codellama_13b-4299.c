//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
// Password Strength Checker
#include <stdio.h>
#include <string.h>

// Function to check password strength
int check_password_strength(char* password) {
    int score = 0;

    // Check for length
    if (strlen(password) > 8) {
        score++;
    }

    // Check for uppercase letters
    int uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercase++;
        }
    }
    if (uppercase > 0) {
        score++;
    }

    // Check for lowercase letters
    int lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            lowercase++;
        }
    }
    if (lowercase > 0) {
        score++;
    }

    // Check for numbers
    int numbers = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            numbers++;
        }
    }
    if (numbers > 0) {
        score++;
    }

    // Check for special characters
    int special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isalpha(password[i]) == 0) {
            special++;
        }
    }
    if (special > 0) {
        score++;
    }

    return score;
}

// Main function
int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);

    int score = check_password_strength(password);
    printf("Password strength: %d\n", score);

    return 0;
}