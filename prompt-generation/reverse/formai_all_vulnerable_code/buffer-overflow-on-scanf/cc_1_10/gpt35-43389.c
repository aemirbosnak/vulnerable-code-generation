//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: introspective
#include <stdio.h>
#include <ctype.h>

// Function to calculate the strength of a password
int password_strength(char password[]) {
    int length = 0, score = 0;
    int upperCaseCount = 0, lowerCaseCount = 0, digitCount = 0, symbolCount = 0;

    // Loop through each character in the password
    for (int i = 0; password[i] != '\0'; i++) {
        length++;
        if (isupper(password[i])) {
            upperCaseCount++;
        } else if (islower(password[i])) {
            lowerCaseCount++;
        } else if (isdigit(password[i])) {
            digitCount++;
        } else {
            symbolCount++;
        }
    }

    // Assign a score to each category
    if (length >= 8) score += 10;
    if (upperCaseCount >= 1) score += 5;
    if (lowerCaseCount >= 1) score += 5;
    if (digitCount >= 1) score += 5;
    if (symbolCount >= 1) score += 5;

    return score;
}

int main() {
    char password[100];

    // Get input from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the strength of the password
    int strength = password_strength(password);

    // Display the strength of the password
    if (strength == 0) {
        printf("Your password is too weak.\n");
    } else if (strength < 20) {
        printf("Your password is weak.\n");
    } else if (strength < 35) {
        printf("Your password is moderate.\n");
    } else if (strength < 50) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is very strong.\n");
    }

    return 0;
}