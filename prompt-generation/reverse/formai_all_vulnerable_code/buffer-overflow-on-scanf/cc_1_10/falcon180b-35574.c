//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char* password;
    int length;
} Password;

Password createPassword(int length) {
    char* password = malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Error: Failed to allocate memory for password.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }

    password[length] = '\0';

    return (Password) {
       .password = password,
       .length = length
    };
}

bool isPasswordValid(Password password) {
    if (password.length < MIN_PASSWORD_LENGTH || password.length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password must be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return false;
    }

    bool hasDigit = false;
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasSpecialChar = false;

    for (int i = 0; i < password.length; i++) {
        char c = tolower(password.password[i]);

        if (isdigit(c)) {
            hasDigit = true;
        } else if (isupper(c)) {
            hasUpperCase = true;
        } else if (islower(c)) {
            hasLowerCase = true;
        } else {
            hasSpecialChar = true;
        }
    }

    if (!hasDigit ||!hasUpperCase ||!hasLowerCase ||!hasSpecialChar) {
        printf("Error: Password must contain at least one digit, one uppercase letter, one lowercase letter, and one special character.\n");
        return false;
    }

    return true;
}

void main() {
    int passwordLength;

    printf("Enter the desired password length (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &passwordLength);

    Password password = createPassword(passwordLength);

    if (isPasswordValid(password)) {
        printf("Your password is: %s\n", password.password);
    }

    free(password.password);
}