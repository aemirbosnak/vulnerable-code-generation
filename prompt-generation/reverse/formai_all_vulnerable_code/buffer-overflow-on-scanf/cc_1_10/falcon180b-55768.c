//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

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

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
            break;
        }
    }

    // Check for symbols
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            symbols = 1;
            break;
        }
    }

    // Determine password strength
    if (length < 8) {
        return 1; // Weak
    } else if (length < 12 || (length > 12 && (uppercase || lowercase))) {
        return 2; // Medium
    } else {
        return 3; // Strong
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    int strength = check_password_strength(password);

    // Print password strength
    switch (strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Medium\n");
            break;
        case 3:
            printf("Strong\n");
            break;
    }

    return 0;
}