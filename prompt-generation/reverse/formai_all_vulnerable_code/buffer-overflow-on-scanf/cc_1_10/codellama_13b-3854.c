//Code Llama-13B DATASET v1.0 Category: Password management ; Style: excited
// C Program to manage passwords

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store passwords
struct Password {
    char name[100];
    char password[100];
};

// Function to create a new password
void createPassword(struct Password *password) {
    // Generate a random password
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        password->password[i] = (char)(rand() % 26 + 65);
    }
    // Ask for name and save it
    printf("Enter name: ");
    scanf("%s", password->name);
}

// Function to retrieve a password
void retrievePassword(struct Password *password) {
    // Ask for name and find the corresponding password
    printf("Enter name: ");
    scanf("%s", password->name);
    for (int i = 0; i < 10; i++) {
        if (password[i].name == password->name) {
            printf("Password: %s\n", password[i].password);
            break;
        }
    }
}

// Function to update a password
void updatePassword(struct Password *password) {
    // Ask for name and find the corresponding password
    printf("Enter name: ");
    scanf("%s", password->name);
    for (int i = 0; i < 10; i++) {
        if (password[i].name == password->name) {
            // Generate a new password
            srand(time(0));
            for (int i = 0; i < 10; i++) {
                password[i].password[i] = (char)(rand() % 26 + 65);
            }
            printf("Password updated: %s\n", password[i].password);
            break;
        }
    }
}

// Function to delete a password
void deletePassword(struct Password *password) {
    // Ask for name and find the corresponding password
    printf("Enter name: ");
    scanf("%s", password->name);
    for (int i = 0; i < 10; i++) {
        if (password[i].name == password->name) {
            // Delete the password
            memset(password[i].name, 0, sizeof(password[i].name));
            memset(password[i].password, 0, sizeof(password[i].password));
            printf("Password deleted\n");
            break;
        }
    }
}

// Main function
int main() {
    // Initialize the passwords
    struct Password passwords[10];
    for (int i = 0; i < 10; i++) {
        createPassword(&passwords[i]);
    }

    // Ask for an option
    char option;
    printf("Enter an option (c/r/u/d): ");
    scanf(" %c", &option);

    // Perform the action
    switch (option) {
        case 'c':
            createPassword(&passwords[0]);
            break;
        case 'r':
            retrievePassword(&passwords[0]);
            break;
        case 'u':
            updatePassword(&passwords[0]);
            break;
        case 'd':
            deletePassword(&passwords[0]);
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}