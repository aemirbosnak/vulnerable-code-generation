//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[256];
    int strength;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password
    if (strlen(password) < 8) {
        strength = 0;
    } else if (strlen(password) < 12) {
        strength = 1;
    } else if (strlen(password) < 16) {
        strength = 2;
    } else {
        strength = 3;
    }

    // Check for uppercase letters
    int hasUpper = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
            break;
        }
    }
    if (hasUpper) {
        strength++;
    }

    // Check for lowercase letters
    int hasLower = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            hasLower = 1;
            break;
        }
    }
    if (hasLower) {
        strength++;
    }

    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }
    if (hasDigit) {
        strength++;
    }

    // Check for special characters
    int hasSpecial = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalpha(password[i]) && !isdigit(password[i])) {
            hasSpecial = 1;
            break;
        }
    }
    if (hasSpecial) {
        strength++;
    }

    // Print the password strength
    printf("Your password strength is: ");
    switch (strength) {
        case 0:
            printf("Weak");
            break;
        case 1:
            printf("Fair");
            break;
        case 2:
            printf("Good");
            break;
        case 3:
            printf("Strong");
            break;
        case 4:
            printf("Excellent");
            break;
        default:
            printf("Invalid");
    }
    printf("\n");

    return 0;
}