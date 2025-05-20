//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
// A Password Strength Checker Program

// Ada Lovelace-style Code

#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int length, upper, lower, digit, special, strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check the length of the password
    if (length < 8) {
        printf("Password is too short. It must have at least 8 characters.\n");
    } else {
        strength++;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
            break;
        }
    }

    if (upper) {
        strength++;
    } else {
        printf("Password must contain at least one uppercase letter.\n");
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
            break;
        }
    }

    if (lower) {
        strength++;
    } else {
        printf("Password must contain at least one lowercase letter.\n");
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
            break;
        }
    }

    if (digit) {
        strength++;
    } else {
        printf("Password must contain at least one digit.\n");
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!(password[i] >= '0' && password[i] <= '9') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= 'A' && password[i] <= 'Z')) {
            special = 1;
            break;
        }
    }

    if (special) {
        strength++;
    } else {
        printf("Password must contain at least one special character.\n");
    }

    // Print the strength of the password
    if (strength == 5) {
        printf("Password is very strong!\n");
    } else if (strength == 4) {
        printf("Password is strong enough.\n");
    } else if (strength == 3) {
        printf("Password is moderate.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}