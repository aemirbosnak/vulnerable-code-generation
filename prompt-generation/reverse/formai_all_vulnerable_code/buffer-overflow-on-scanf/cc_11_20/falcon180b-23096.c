//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;
    int uppercase_count;
    int lowercase_count;
    int digit_count;
    int special_count;
    int strength;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for uppercase characters
    uppercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for lowercase characters
    lowercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for digits
    digit_count = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    special_count = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // Calculate password strength
    if (length < 8) {
        strength = 1;
    } else if (length < 16) {
        strength = 2;
    } else if (length < 24) {
        strength = 3;
    } else {
        strength = 4;
    }

    if (uppercase_count > 0) {
        strength++;
    }

    if (lowercase_count > 0) {
        strength++;
    }

    if (digit_count > 0) {
        strength++;
    }

    if (special_count > 0) {
        strength++;
    }

    printf("Password strength: ");
    switch (strength) {
        case 1:
            printf("Very Weak\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        case 3:
            printf("Moderate\n");
            break;
        case 4:
            printf("Strong\n");
            break;
        default:
            printf("Very Strong\n");
            break;
    }

    return 0;
}