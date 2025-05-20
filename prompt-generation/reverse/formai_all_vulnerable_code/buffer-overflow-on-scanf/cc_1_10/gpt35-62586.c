//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

int main() {
    // Declare variables
    int passwordLength, i, randomNumber;
    char password[MAX_PASSWORD_LENGTH + 1];

    // Seed the random number generator
    srand(time(NULL));

    // Get password length from user
    do {
        printf("Enter password length: ");
        scanf("%d", &passwordLength);

        if (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
            printf("Password must be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        }
    } while (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH);

    // Generate password
    for (i = 0; i < passwordLength; i++) {
        randomNumber = rand() % 93 + 33;
        password[i] = (char) randomNumber;
    }

    password[passwordLength] = '\0';

    // Check password requirements
    if (!hasUpperCase(password) || !hasLowerCase(password) || !hasDigit(password)) {
        printf("Generated password does not meet requirements.\n");
    } else {
        printf("Generated password: %s\n", password);
    }

    return 0;
}

// Function to check if password contains at least one uppercase letter
int hasUpperCase(char password[]) {
    int i;
    for (i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains at least one lowercase letter
int hasLowerCase(char password[]) {
    int i;
    for (i = 0; password[i]; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains at least one digit
int hasDigit(char password[]) {
    int i;
    for (i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}