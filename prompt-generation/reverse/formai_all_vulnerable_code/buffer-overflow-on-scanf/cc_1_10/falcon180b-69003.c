//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];

    // Prompt the user for a password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the password is within the allowed length
    if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Password must be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Initialize the password strength to zero
    int strength = 0;

    // Check if the password contains uppercase letters
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") > 0) {
        strength++;
    }

    // Check if the password contains lowercase letters
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") > 0) {
        strength++;
    }

    // Check if the password contains digits
    if (strspn(password, "0123456789") > 0) {
        strength++;
    }

    // Check if the password contains special characters
    if (strspn(password, "!@#$%^&*()_-+={}[]\\|;:'\",.<>/?") > 0) {
        strength++;
    }

    // Print the password strength
    if (strength == 0) {
        printf("Weak password.\n");
    } else if (strength == 1) {
        printf("Moderate password.\n");
    } else if (strength == 2) {
        printf("Strong password.\n");
    } else {
        printf("Very strong password.\n");
    }

    return 0;
}