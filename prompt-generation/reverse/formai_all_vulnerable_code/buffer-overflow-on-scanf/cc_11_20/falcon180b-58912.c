//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, upper_count = 0, lower_count = 0, digit_count = 0, special_count = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_count++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower_count++;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    int strength = 0;

    // Calculate password strength
    if (length >= 8) {
        strength++;
    }
    if (upper_count > 0) {
        strength++;
    }
    if (lower_count > 0) {
        strength++;
    }
    if (digit_count > 0) {
        strength++;
    }
    if (special_count > 0) {
        strength++;
    }

    if (strength <= 1) {
        printf("Weak password\n");
    } else if (strength <= 3) {
        printf("Moderate password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}