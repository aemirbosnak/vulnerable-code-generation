//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Function to check if the password contains at least one uppercase letter
bool contains_uppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one lowercase letter
bool contains_lowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one digit
bool contains_digit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one special character
bool contains_special(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password meets the minimum length requirement
bool meets_length_requirement(char* password) {
    return strlen(password) >= 8;
}

// Function to check if the password meets all the strength requirements
bool is_strong_password(char* password) {
    return contains_uppercase(password) && contains_lowercase(password) && contains_digit(password) && contains_special(password) && meets_length_requirement(password);
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_strong_password(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}