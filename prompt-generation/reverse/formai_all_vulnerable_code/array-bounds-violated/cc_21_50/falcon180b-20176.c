//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length, i;
    int uppercase = 0, lowercase = 0, number = 0, special = 0;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);

    // Remove the newline character from the input
    length = strlen(password) - 1;
    password[length] = '\0';

    // Check if the password is too short
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check if the password contains at least one uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check if the password contains at least one number
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            number = 1;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Calculate the strength of the password
    int strength = 0;
    if (uppercase && lowercase && number && special) {
        strength = 4;
    } else if (uppercase && lowercase && number) {
        strength = 3;
    } else if (uppercase && lowercase && special) {
        strength = 3;
    } else if (uppercase && number && special) {
        strength = 3;
    } else if (lowercase && number && special) {
        strength = 3;
    } else if (uppercase && lowercase) {
        strength = 2;
    } else if (uppercase && number) {
        strength = 2;
    } else if (lowercase && number) {
        strength = 2;
    } else if (uppercase && special) {
        strength = 2;
    } else if (lowercase && special) {
        strength = 2;
    } else if (number && special) {
        strength = 2;
    } else {
        strength = 1;
    }

    // Print the strength of the password
    printf("Password strength: %d\n", strength);

    return 0;
}