//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    length = strlen(password);

    // Remove the newline character from the end of the password
    password[--length] = '\0';

    // Check if the password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
    if (hasUppercase(password) && hasLowercase(password) && hasDigit(password) && hasSpecialChar(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

/*
 * This function checks if the given password contains at least one uppercase letter.
 * Returns 1 if true, 0 otherwise.
 */
int hasUppercase(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

/*
 * This function checks if the given password contains at least one lowercase letter.
 * Returns 1 if true, 0 otherwise.
 */
int hasLowercase(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

/*
 * This function checks if the given password contains at least one digit.
 * Returns 1 if true, 0 otherwise.
 */
int hasDigit(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

/*
 * This function checks if the given password contains at least one special character.
 * Returns 1 if true, 0 otherwise.
 */
int hasSpecialChar(char* password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}