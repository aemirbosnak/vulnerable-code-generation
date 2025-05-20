//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase = 0, lowercase = 0, numbers = 0, symbols = 0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check if password contains uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check if password contains lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check if password contains numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
            break;
        }
    }

    // Check if password contains symbols
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            symbols = 1;
            break;
        }
    }

    // Determine password strength based on criteria
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (uppercase) {
        strength++;
    }
    if (lowercase) {
        strength++;
    }
    if (numbers) {
        strength++;
    }
    if (symbols) {
        strength++;
    }

    // Print password strength
    if (strength == 0) {
        printf("Password is very weak.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else if (strength == 3) {
        printf("Password is strong.\n");
    } else {
        printf("Password is very strong.\n");
    }

    return 0;
}