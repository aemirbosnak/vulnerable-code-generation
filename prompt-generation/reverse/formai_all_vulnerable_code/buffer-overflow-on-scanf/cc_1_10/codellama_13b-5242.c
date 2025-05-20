//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Ada Lovelace
// Ada Lovelace Password Strength Checker
// A program to check the strength of a password

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

// Define a struct to represent a password
struct Password {
    char password[MAX_PASSWORD_LENGTH];
    int length;
};

// Function to check the strength of a password
int check_password_strength(struct Password password) {
    int length = strlen(password.password);
    if (length < 8) {
        return 0;
    }
    if (length > 12) {
        return 2;
    }
    if (strchr(password.password, ' ') != NULL) {
        return 0;
    }
    if (strchr(password.password, '!') != NULL) {
        return 2;
    }
    return 1;
}

// Function to print the strength of a password
void print_password_strength(struct Password password) {
    int strength = check_password_strength(password);
    switch (strength) {
        case 0:
            printf("The password is too weak.\n");
            break;
        case 1:
            printf("The password is weak.\n");
            break;
        case 2:
            printf("The password is strong.\n");
            break;
    }
}

// Main function
int main() {
    struct Password password;
    printf("Enter a password: ");
    scanf("%s", password.password);
    password.length = strlen(password.password);
    print_password_strength(password);
    return 0;
}