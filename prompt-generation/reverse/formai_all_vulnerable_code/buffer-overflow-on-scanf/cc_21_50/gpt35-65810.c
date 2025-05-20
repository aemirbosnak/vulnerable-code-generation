//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
    char password[30];

    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int score = 0;

    // Calculate length score
    if (length >= 8) {
        score += 5;
    } else if (length >= 6) {
        score += 3;
    } else if (length >= 4) {
        score += 1;
    }

    // Check for upper and lowercase letters
    int has_upper = 0;
    int has_lower = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_upper = 1;
        }
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lower = 1;
        }
    }
    if (has_upper && has_lower) {
        score += 5;
    } else if (has_upper || has_lower) {
        score += 3;
    }

    // Check for digits
    int has_digit = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        }
    }
    if (has_digit) {
        score += 5;
    }

    // Check for special characters
    int has_special = 0;
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>/?";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                has_special = 1;
            }
        }
    }
    if (has_special) {
        score += 5;
    }

    // Print password strength and score
    printf("Password strength: ");
    if (score >= 15) {
        printf("Strong\n");
    } else if (score >= 10) {
        printf("Moderate\n");
    } else {
        printf("Weak\n");
    }
    printf("Score: %d\n", score);

    return 0;
}