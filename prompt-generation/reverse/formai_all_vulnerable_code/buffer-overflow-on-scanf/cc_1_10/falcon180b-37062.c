//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 8

// Function to check if the password is strong enough
int checkPassword(char password[]) {
    int i, j, count = 0, upper = 0, lower = 0, digit = 0, special = 0;

    // Initialize counters
    for (i = 0; i < SIZE; i++) {
        count++;
    }

    // Check for uppercase letters
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            upper++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            lower++;
        }
    }

    // Check for digits
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            digit++;
        }
    }

    // Check for special characters
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            special++;
        }
    }

    // Check if the password is strong enough
    if (count >= SIZE && upper >= 1 && lower >= 1 && digit >= 1 && special >= 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[50];

    // Get the password from the user
    printf("Enter the password: ");
    scanf("%s", password);

    // Check if the password is strong enough
    if (checkPassword(password)) {
        printf("Password is strong enough\n");
    } else {
        printf("Password is not strong enough\n");
    }

    return 0;
}