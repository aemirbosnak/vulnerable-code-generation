//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 30

int main() {
    char password[MAX_LENGTH];
    int length, uppercase, lowercase, digit, special, strength;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);
    length = strlen(password);

    // Check for uppercase letters
    uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for digits
    digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check for special characters
    special = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Calculate password strength
    strength = 0;
    if (uppercase) {
        strength++;
    }
    if (lowercase) {
        strength++;
    }
    if (digit) {
        strength++;
    }
    if (special) {
        strength++;
    }
    if (length >= 8) {
        strength++;
    }

    // Print password strength
    if (strength == 0) {
        printf("Very weak password\n");
    } else if (strength == 1) {
        printf("Weak password\n");
    } else if (strength == 2) {
        printf("Moderate password\n");
    } else if (strength == 3) {
        printf("Strong password\n");
    } else {
        printf("Very strong password\n");
    }

    return 0;
}