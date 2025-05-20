//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Function to check if the password contains at least one uppercase letter
int containsUpperCase(char password[]) {
    int i;

    for(i = 0; i < strlen(password); i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            return 1; // Return true if uppercase letter found
        }
    }

    return 0; // Return false if no uppercase letter found
}

// Function to check if the password contains at least one lowercase letter
int containsLowerCase(char password[]) {
    int i;

    for(i = 0; i < strlen(password); i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            return 1; // Return true if lowercase letter found
        }
    }

    return 0; // Return false if no lowercase letter found
}

// Function to check if the password contains at least one digit
int containsDigit(char password[]) {
    int i;

    for(i = 0; i < strlen(password); i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            return 1; // Return true if digit found
        }
    }

    return 0; // Return false if no digit found
}

// Function to check if the password contains at least one special character
int containsSpecialChar(char password[]) {
    int i;

    for(i = 0; i < strlen(password); i++) {
        if(!(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= '0' && password[i] <= '9') && password[i] != ' ') {
            return 1; // Return true if special character found
        }
    }

    return 0; // Return false if no special character found
}

// Function to check the strength of the password and return a score
int getPasswordStrength(char password[]) {
    int score = 0;

    if(strlen(password) >= 8) {
        score++; // Add one point for length of at least 8 characters
    }

    if(containsUpperCase(password)) {
        score++; // Add one point for containing at least one uppercase letter
    }

    if(containsLowerCase(password)) {
        score++; // Add one point for containing at least one lowercase letter
    }

    if(containsDigit(password)) {
        score++; // Add one point for containing at least one digit
    }

    if(containsSpecialChar(password)) {
        score++; // Add one point for containing at least one special character
    }

    return score; // Return the total score
}

int main() {
    char password[100];

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character at the end of the password
    if(password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    int strength = getPasswordStrength(password);

    printf("Your password scored %d out of 5 in strength.\n", strength);

    switch(strength) {
        case 0:
            printf("Your password is extremely weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is somewhat strong.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is extremely strong.\n");
            break;
        case 5:
            printf("Your password is perfect!\n");
            break;
    }

    return 0;
}