//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 50

int main() {
    char password[MAX_PASSWORD_LEN];
    printf("Enter a password: ");
    scanf("%s", password);

    // Initialize password strength to 0
    int strength = 0;

    // Check for minimum password length
    if (strlen(password) < 6) {
        printf("Password must be at least 6 characters long.\n");
        return 1;
    }

    // Check for at least one uppercase letter
    int hasUpper = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        }
    }
    if (!hasUpper) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for at least one lowercase letter
    int hasLower = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            hasLower = 1;
        }
    }
    if (!hasLower) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for at least one digit
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }
    if (!hasDigit) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    // Check for at least one special character
    int hasSpecial = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            hasSpecial = 1;
        }
    }
    if (!hasSpecial) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    // Check for repeated characters
    int hasRepeated = 0;
    for (int i = 0; i < strlen(password) - 1; i++) {
        if (password[i] == password[i + 1]) {
            hasRepeated = 1;
        }
    }
    if (hasRepeated) {
        printf("Password must not have repeated characters.\n");
        return 1;
    }

    // Check for common patterns
    int hasCommon = 0;
    if (strstr(password, "123456") || strstr(password, "12345678") ||
        strstr(password, "123456789") || strstr(password, "abc123") ||
        strstr(password, "qwerty") || strstr(password, "password") ||
        strstr(password, "admin") || strstr(password, "letmein") ||
        strstr(password, "monkey")) {
        printf("Password must not contain common patterns.\n");
        return 1;
    }

    // Check for dictionary words
    int hasDictionary = 0;
    if (strstr(password, "password") || strstr(password, "admin") ||
        strstr(password, "123456") || strstr(password, "qwerty") ||
        strstr(password, "letmein") || strstr(password, "monkey") ||
        strstr(password, "12345678") || strstr(password, "password1") ||
        strstr(password, "123456789") || strstr(password, "abc123")) {
        printf("Password must not contain dictionary words.\n");
        return 1;
    }

    // Check for alternating case
    int hasAlternate = 0;
    for (int i = 0; i < strlen(password) - 1; i++) {
        if (tolower(password[i])!= tolower(password[i + 1])) {
            hasAlternate = 1;
        }
    }
    if (!hasAlternate) {
        printf("Password must contain alternating case.\n");
        return 1;
    }

    // Check for all conditions met
    if (strength == 10) {
        printf("Password strength: Strong\n");
    } else if (strength == 7) {
        printf("Password strength: Moderate\n");
    } else {
        printf("Password strength: Weak\n");
    }

    return 0;
}