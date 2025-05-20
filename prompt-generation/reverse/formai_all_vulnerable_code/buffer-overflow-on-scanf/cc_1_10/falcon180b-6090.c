//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50
#define MIN_PASSWORD_LENGTH 8

// Function to check if the password contains at least one uppercase letter
int contains_uppercase(char *password) {
    int i = 0;
    while (password[i]!= '\0') {
        if (isupper(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int contains_lowercase(char *password) {
    int i = 0;
    while (password[i]!= '\0') {
        if (islower(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check if the password contains at least one digit
int contains_digit(char *password) {
    int i = 0;
    while (password[i]!= '\0') {
        if (isdigit(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check if the password contains at least one special character
int contains_special_char(char *password) {
    int i = 0;
    while (password[i]!= '\0') {
        if (!isalnum(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to check the strength of the password
int check_password_strength(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }
    if (contains_uppercase(password)) {
        printf("The password contains at least one uppercase letter.\n");
    } else {
        printf("The password does not contain any uppercase letter.\n");
    }
    if (contains_lowercase(password)) {
        printf("The password contains at least one lowercase letter.\n");
    } else {
        printf("The password does not contain any lowercase letter.\n");
    }
    if (contains_digit(password)) {
        printf("The password contains at least one digit.\n");
    } else {
        printf("The password does not contain any digit.\n");
    }
    if (contains_special_char(password)) {
        printf("The password contains at least one special character.\n");
    } else {
        printf("The password does not contain any special character.\n");
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}