//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char password[100];
    int length;
    bool uppercase = false, lowercase = false, digit = false, special = false;

    // Prompt user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = true;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = true;
            break;
        }
    }

    // Check for digit
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = true;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = true;
            break;
        }
    }

    // Print password strength
    if (uppercase && lowercase && digit && special) {
        printf("Password is very strong.\n");
    } else if (uppercase && lowercase && digit) {
        printf("Password is strong.\n");
    } else if (uppercase && lowercase) {
        printf("Password is moderate.\n");
    } else if (digit && special) {
        printf("Password is moderate.\n");
    } else if (uppercase || lowercase || digit || special) {
        printf("Password is weak.\n");
    } else {
        printf("Password is very weak.\n");
    }

    return 0;
}