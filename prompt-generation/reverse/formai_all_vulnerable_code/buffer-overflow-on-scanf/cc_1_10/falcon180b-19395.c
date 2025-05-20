//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, numbers = 0, symbols = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
        }
    }

    // Check for symbols
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            symbols = 1;
        }
    }

    // Calculate password strength based on number of character types
    int strength = 0;
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

    return strength;
}

int main() {
    char password[100];

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    int strength = check_password_strength(password);

    // Print password strength
    if (strength == 0) {
        printf("Weak\n");
    } else if (strength == 1) {
        printf("Fair\n");
    } else if (strength == 2) {
        printf("Good\n");
    } else if (strength == 3) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}