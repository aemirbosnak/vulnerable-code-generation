//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, uppercase = 0, lowercase = 0, digit = 0, special_char = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_char = 1;
            break;
        }
    }

    int strength = 0;

    // Calculate password strength
    if (length >= 8) {
        strength++;
    }
    if (uppercase) {
        strength++;
    }
    if (lowercase) {
        strength++;
    }
    if (digit) {
        strength++;
    }
    if (special_char) {
        strength++;
    }

    printf("Password strength: ");
    if (strength <= 1) {
        printf("Very Weak\n");
    } else if (strength <= 3) {
        printf("Weak\n");
    } else if (strength <= 5) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}