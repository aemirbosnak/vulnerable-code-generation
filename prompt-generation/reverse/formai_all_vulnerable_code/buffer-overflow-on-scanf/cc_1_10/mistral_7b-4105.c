//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MIN_UPPER 2
#define MIN_DIGITS 2
#define MIN_SPECIAL 1

// Function to check if a character is a digit
int isdigit_helper(char c) {
    return (isdigit(c) != 0);
}

// Function to check if a character is an uppercase letter
int isupper_helper(char c) {
    return (isupper(c) != 0);
}

// Function to check if a character is a lowercase letter
int islower_helper(char c) {
    return (islower(c) != 0);
}

// Function to check if a character is a special character
int isspecial_helper(char c) {
    return (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/\"?`~", c) != NULL);
}

// Function to check the password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int upper = 0, digits = 0, special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper_helper(password[i])) {
            upper++;
        }
        if (isdigit_helper(password[i])) {
            digits++;
        }
        if (isspecial_helper(password[i])) {
            special++;
        }
    }

    // Romeo's Password Requirements
    if (length >= MIN_LENGTH && upper >= MIN_UPPER && digits >= MIN_DIGITS && special >= MIN_SPECIAL) {
        printf("Password '%s' is strong like Romeo's love for Juliet.\n", password);
        return 1;
    }

    // Juliet's Password Requirements
    if (length >= MIN_LENGTH && (upper || digits || special)) {
        printf("Password '%s' is better than a rose, it's not easily broken.\n", password);
        return 1;
    }

    // If neither Romeo nor Juliet are satisfied, the password is weak
    printf("Password '%s' is as weak as a wind that carries empty words.\n", password);
    return 0;
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}