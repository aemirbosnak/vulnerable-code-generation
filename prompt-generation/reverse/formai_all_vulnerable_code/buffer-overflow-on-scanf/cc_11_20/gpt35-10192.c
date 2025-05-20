//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int i, length, score = 0, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    length = strlen(password);

    // Check if password is at least 8 characters long
    if (length < 8) {
        printf("Your password is too short.\n");
        printf("Please enter a password with at least 8 characters.\n");
        return 0;
    }

    // Check for uppercase, lowercase, digits, and special characters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
        }
        if (islower(password[i])) {
            lower = 1;
        }
        if (isdigit(password[i])) {
            digit = 1;
        }
        if (!isalnum(password[i])) {
            special = 1;
        }
    }

    // Calculate score based on password complexity
    if (upper == 1) {
        score++;
    }
    if (lower == 1) {
        score++;
    }
    if (digit == 1) {
        score++;
    }
    if (special == 1) {
        score++;
    }

    // Print the strength of the password based on its score
    printf("Your password has a score of %d out of 4.\n", score);
    switch (score) {
        case 0:
            printf("Your password is extremely weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderately strong.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is extremely strong.\n");
            break;
    }

    return 0;
}