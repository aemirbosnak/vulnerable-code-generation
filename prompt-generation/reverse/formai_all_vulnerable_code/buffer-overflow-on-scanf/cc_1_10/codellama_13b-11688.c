//Code Llama-13B DATASET v1.0 Category: Password management ; Style: all-encompassing
// A simple password management program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store the password
struct Password {
    char username[20];
    char password[20];
};

// Function to add a new password
void addPassword(struct Password* pass, char* username, char* password) {
    strcpy(pass->username, username);
    strcpy(pass->password, password);
}

// Function to authenticate a password
bool authenticatePassword(struct Password* pass, char* username, char* password) {
    return (strcmp(pass->username, username) == 0 && strcmp(pass->password, password) == 0);
}

// Function to delete a password
void deletePassword(struct Password* pass) {
    memset(pass, 0, sizeof(struct Password));
}

int main() {
    struct Password pass;
    char username[20];
    char password[20];
    char new_username[20];
    char new_password[20];

    // Add a new password
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    addPassword(&pass, username, password);

    // Authenticate the password
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (authenticatePassword(&pass, username, password)) {
        printf("Authentication successful.\n");
    } else {
        printf("Authentication failed.\n");
    }

    // Delete the password
    deletePassword(&pass);

    return 0;
}