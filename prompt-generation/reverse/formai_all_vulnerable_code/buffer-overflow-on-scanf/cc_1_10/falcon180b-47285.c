//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 10

// Function to check if the password is strong
int checkPassword(char *password) {
    int length = strlen(password);
    int lowercase = 0, uppercase = 0, digits = 0, special = 0;
    int found = 0;

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            found = 1;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            found = 1;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digits = 1;
            found = 1;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            found = 1;
        }
    }

    // Check if all types of characters are present
    if (lowercase && uppercase && digits && special) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[LENGTH];
    int strength = 0;

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    strength = checkPassword(password);

    // Print password strength
    if (strength == 1) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}