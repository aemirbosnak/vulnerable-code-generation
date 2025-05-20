//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password;

// Define the array of passwords
password passwords[NUM_PASSWORDS];

// Prompt the user to enter a username and password
void get_credentials(char *username, char *password) {
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
}

// Store a password in the array
void store_password(char *username, char *password) {
    // Find an empty slot in the array
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (strlen(passwords[i].username) == 0) {
            break;
        }
    }

    // If there is no empty slot, print an error message
    if (i == NUM_PASSWORDS) {
        printf("Error: Password array is full.\n");
        return;
    }

    // Store the username and password in the array
    strcpy(passwords[i].username, username);
    strcpy(passwords[i].password, password);
}

// Retrieve a password from the array
void retrieve_password(char *username, char *password) {
    // Find the password in the array
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    // If the password was not found, print an error message
    if (i == NUM_PASSWORDS) {
        printf("Error: Password not found.\n");
        return;
    }

    // Copy the password to the output buffer
    strcpy(password, passwords[i].password);
}

// Print the passwords in the array
void print_passwords() {
    // Iterate over the array and print each password
    int i;
    for (i = 0; i < NUM_PASSWORDS; i++) {
        if (strlen(passwords[i].username) == 0) {
            continue;
        }
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Main function
int main() {
    // Get the user's credentials
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    get_credentials(username, password);

    // Store the password in the array
    store_password(username, password);

    // Retrieve the password from the array
    char retrieved_password[MAX_PASSWORD_LENGTH];
    retrieve_password(username, retrieved_password);

    // Print the retrieved password
    printf("Retrieved password: %s\n", retrieved_password);

    // Print all the passwords in the array
    print_passwords();

    return 0;
}