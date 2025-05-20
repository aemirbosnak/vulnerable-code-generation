//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, upper, lower, digit, special;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short (minimum 8 characters).\n");
        return 0;
    }

    // Check for uppercase letter
    upper = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
            break;
        }
    }
    if (!upper) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letter
    lower = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower = 1;
            break;
        }
    }
    if (!lower) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for digit
    digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }
    if (!digit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    // Check for special character
    special = 0;
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                special = 1;
                break;
            }
        }
        if (special) {
            break;
        }
    }
    if (!special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Password meets all requirements
    printf("Password is strong.\n");
    return 0;
}