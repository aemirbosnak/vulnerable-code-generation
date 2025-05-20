//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LENGTH 8

int main() {
    char password[LENGTH + 1];
    int strength = 0;

    // Prompt user for password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check length of password
    if (strlen(password) < LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for uppercase letters
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    strength++;

    // Check for lowercase letters
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    strength++;

    // Check for digits
    if (strspn(password, "0123456789") == 0) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    strength++;

    // Check for special characters
    if (strspn(password, "!@#$%^&*()_+-=[]{}|;:,.<>?") == 0) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    strength++;

    // Determine password strength
    if (strength == 0) {
        printf("Password is very weak.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else if (strength == 3) {
        printf("Password is strong.\n");
    } else if (strength == 4) {
        printf("Password is very strong.\n");
    }

    return 0;
}