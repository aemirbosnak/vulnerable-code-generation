//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_MAX_LENGTH 100

// Function to check if the password contains any special characters
int contains_special_chars(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains any numbers
int contains_numbers(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains any uppercase letters
int contains_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains any lowercase letters
int contains_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check the strength of the password
int check_password_strength(char *password) {
    int strength = 0;
    if (strlen(password) < 8) {
        printf("Password is too short.\n");
        return 0;
    }
    if (contains_special_chars(password)) {
        strength++;
    }
    if (contains_numbers(password)) {
        strength++;
    }
    if (contains_uppercase(password)) {
        strength++;
    }
    if (contains_lowercase(password)) {
        strength++;
    }
    switch (strength) {
        case 0:
            printf("Password is very weak.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
    }
    return strength;
}

int main() {
    char password[PASSWORD_MAX_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}