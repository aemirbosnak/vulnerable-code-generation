//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a special character
int isSpecial(char ch) {
    if (ch >= 33 && ch <= 47) {
        return 1;
    } else if (ch >= 58 && ch <= 64) {
        return 1;
    } else if (ch >= 91 && ch <= 96) {
        return 1;
    } else if (ch >= 123 && ch <= 126) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[50];
    int length, i, hasUpper = 0, hasLower = 0, hasNum = 0, hasSpecial = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check password length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check password characters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasNum = 1;
        } else if (isSpecial(password[i])) {
            hasSpecial = 1;
        }
    }

    // Determine password strength and provide feedback
    if (hasUpper && hasLower && hasNum && hasSpecial) {
        printf("Password strength: Strong\n");
    } else if ((hasUpper && hasLower && hasSpecial) || (hasUpper && hasNum && hasSpecial) || (hasLower && hasNum && hasSpecial)) {
        printf("Password strength: Medium\n");
    } else {
        printf("Password strength: Weak\n");
    }

    return 0;
}