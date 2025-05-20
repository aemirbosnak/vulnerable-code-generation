//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8

// Function to check if character is a letter or number
int is_valid_char(char c) {
    if (isalpha(c) || isdigit(c)) {
        return 1;
    }
    return 0;
}

// Function to check if password contains uppercase, lowercase, and number
int check_password(char *password) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_number) {
        return 1;
    }
    return 0;
}

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int complexity = 0;

    if (length >= MAX_LENGTH) {
        complexity += 1;
    }

    if (length >= MIN_LENGTH) {
        complexity += 1;
    }

    if (check_password(password)) {
        complexity += 1;
    }

    if (length > MAX_LENGTH) {
        printf("Password is too long\n");
    } else if (length < MIN_LENGTH) {
        printf("Password is too short\n");
    } else if (complexity == 0) {
        printf("Password is weak\n");
    } else if (complexity == 1) {
        printf("Password is medium\n");
    } else {
        printf("Password is strong\n");
    }
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}