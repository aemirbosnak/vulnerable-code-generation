//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
// PasswordStrengthChecker.c

#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    int i, score = 0;

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);

    // Check for length
    if (strlen(password) < 8) {
        printf("Password too short, minimum 8 characters\n");
    }

    // Check for lowercase letters
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            score++;
        }
    }

    // Check for uppercase letters
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            score++;
        }
    }

    // Check for numbers
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            score++;
        }
    }

    // Check for special characters
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= '!' && password[i] <= '/') {
            score++;
        }
    }

    // Check for repeating characters
    for (i = 0; i < strlen(password); i++) {
        if (password[i] == password[i - 1]) {
            score--;
        }
    }

    printf("Password strength: %d\n", score);

    return 0;
}