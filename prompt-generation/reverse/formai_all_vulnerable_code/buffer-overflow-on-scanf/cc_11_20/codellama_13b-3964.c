//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
/*
 * A unique C Password Strength Checker example program in an interoperable style
 */

#include <stdio.h>
#include <string.h>

// Define a function to check the password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    int special = 0;
    int score = 0;

    // Check the password length
    if (length < 8) {
        score = 0;
    } else if (length < 12) {
        score = 1;
    } else {
        score = 2;
    }

    // Check the password complexity
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            number = 1;
        } else {
            special = 1;
        }
    }

    if (uppercase && lowercase && number && special) {
        score += 2;
    } else if (uppercase && lowercase && number) {
        score += 1;
    } else if (uppercase && lowercase && special) {
        score += 1;
    } else if (uppercase && number && special) {
        score += 1;
    } else if (lowercase && number && special) {
        score += 1;
    }

    return score;
}

int main() {
    char password[128];

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the password strength
    int score = check_password_strength(password);

    // Print the password strength score
    if (score == 0) {
        printf("Password is too weak.\n");
    } else if (score == 1) {
        printf("Password is weak.\n");
    } else if (score == 2) {
        printf("Password is medium.\n");
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}