//Code Llama-13B DATASET v1.0 Category: Password management ; Style: optimized
/*
 * C Password Management Program
 *
 * This program provides a simple password management system using a
 * hash function to store and compare passwords.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

// Hash function
unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

// Check if the password is valid
bool check_password(const char *password, const char *hashed_password) {
    return (hash(password) == strtoul(hashed_password, NULL, 10));
}

// Main function
int main() {
    char password[100];
    char hashed_password[100];

    printf("Enter the password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0;

    // Hash the password
    hashed_password[0] = '\0';
    strcat(hashed_password, hash(password));

    // Check if the password is valid
    if (check_password(password, hashed_password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid.\n");
    }

    return 0;
}