//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int i;

    // Prompt the user to enter a password
    printf("Enter a password: ");

    // Read the password from the user
    if (fgets(password, MAX_PASSWORD_LENGTH + 1, stdin) == NULL) {
        printf("Error: Failed to read password.\n");
        return 1;
    }

    // Remove the newline character from the password
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    // Get the length of the password
    password_length = strlen(password);

    // Check if the password is empty
    if (password_length == 0) {
        printf("Error: Password cannot be empty.\n");
        return 1;
    }

    // Check if the password contains only letters and numbers
    for (i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            printf("Error: Password can only contain letters and numbers.\n");
            return 1;
        }
    }

    // Check the strength of the password
    if (password_length < 8) {
        printf("Weak password.\n");
    } else if (password_length < 12) {
        printf("Moderate password.\n");
    } else {
        printf("Strong password.\n");
    }

    return 0;
}