//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short. ");
        return 0;
    }

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
            special = 1;
            break;
        }
    }

    // Determine password strength
    if (uppercase && lowercase && digit && special) {
        printf("Password is very strong. ");
    } else if (uppercase && lowercase && digit) {
        printf("Password is strong. ");
    } else if (uppercase && lowercase || digit && special) {
        printf("Password is moderate. ");
    } else {
        printf("Password is weak. ");
    }

    return 0;
}