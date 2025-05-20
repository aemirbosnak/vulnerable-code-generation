//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int uppercase = 0, lowercase = 0, digit = 0, length, i, strength = 0;
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter a password to check: ");
    scanf("%s", password);
    length = strlen(password);

    // Check password length
    if (length < 8) {
        printf("Your password is weak. It should be at least 8 characters long.\n");
    } else {
        strength += 1;
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        }
    }
    if (uppercase == 1) {
        strength += 1;
    } else {
        printf("Your password is weak. It should contain at least one uppercase letter.\n");
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
        }
    }
    if (lowercase == 1) {
        strength += 1;
    } else {
        printf("Your password is weak. It should contain at least one lowercase letter.\n");
    }

    // Check for digits
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
        }
    }
    if (digit == 1) {
        strength += 1;
    } else {
        printf("Your password is weak. It should contain at least one digit.\n");
    }

    // Check password strength
    switch(strength) {
        case 0:
            printf("Your password is very weak. Please create a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please consider improving it.\n");
            break;
        case 2:
            printf("Your password is moderate. It could be stronger, but it's not bad.\n");
            break;
        case 3:
            printf("Your password is strong! Great job.\n");
            break;
        case 4:
            printf("Your password is very strong! Excellent work!\n");
            break;
    }
    return 0;
}