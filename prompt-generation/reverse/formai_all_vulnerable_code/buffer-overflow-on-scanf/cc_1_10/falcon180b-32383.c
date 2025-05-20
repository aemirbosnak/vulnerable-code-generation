//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if the password is strong enough
int check_password_strength(char* password) {
    // Check if the password is too short
    if (strlen(password) < 8) {
        printf("Password is too short. Must be at least 8 characters.\n");
        return 0;
    }

    // Check if the password contains at least one uppercase letter
    if (!isupper(password[0])) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check if the password contains at least one lowercase letter
    if (!islower(password[0])) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check if the password contains at least one digit
    if (!isdigit(password[0])) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    // Check if the password contains at least one special character
    if (!strpbrk(password, "!@#$%^&*()_-+={}[]|\:;\"'<>,.?/~`")) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Password is strong enough.\n");
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is strong enough
    if (check_password_strength(password)) {
        printf("Password is strong enough.\n");
    } else {
        printf("Password is not strong enough.\n");
    }

    return 0;
}