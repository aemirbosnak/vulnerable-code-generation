//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

// function to check if the password contains at least one digit
int has_digit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// function to check if the password contains at least one lowercase letter
int has_lower(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// function to check if the password contains at least one uppercase letter
int has_upper(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// function to check if the password contains at least one special character
int has_special(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int digit = 0, lower = 0, upper = 0, special = 0;
    
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }
    
    // check if the password meets the minimum length requirement
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }
    
    // check if the password meets the maximum length requirement
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Password cannot exceed %d characters.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }
    
    // check if the password contains a digit, lowercase, uppercase, and special character
    digit = has_digit(password);
    lower = has_lower(password);
    upper = has_upper(password);
    special = has_special(password);
    
    if (!digit) {
        printf("Password must include at least one digit.\n");
    }
    if (!lower) {
        printf("Password must include at least one lowercase letter.\n");
    }
    if (!upper) {
        printf("Password must include at least one uppercase letter.\n");
    }
    if (!special) {
        printf("Password must include at least one special character.\n");
    }
    if (digit && lower && upper && special) {
        printf("Password meets the strength requirements.\n");
    }
    
    return 0;
}