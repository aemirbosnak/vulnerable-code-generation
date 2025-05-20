//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8

// Function to check if the password contains at least one uppercase letter
int contains_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int contains_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one digit
int contains_digit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one special character
int contains_special_char(char *password) {
    char special_chars[] = "!@#$%^&*()_-+=[]{}|;:,.<>?";
    int i, j;
    for (i = 0; i < strlen(password); i++) {
        for (j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check the strength of the password
char *check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = contains_uppercase(password);
    int lowercase = contains_lowercase(password);
    int digit = contains_digit(password);
    int special_char = contains_special_char(password);

    if (length < MIN_LENGTH) {
        return "Password is too short. ";
    } else if (length <= MAX_LENGTH && uppercase && lowercase && digit && special_char) {
        return "Password is strong. ";
    } else if (length <= MAX_LENGTH && (uppercase || lowercase) && digit) {
        return "Password is moderate. ";
    } else {
        return "Password is weak. ";
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    char *result = check_password_strength(password);
    printf("%s\n", result);
    return 0;
}