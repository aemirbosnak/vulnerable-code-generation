//GEMINI-pro DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the maximum number of passwords to store
#define MAX_PASSWORDS 10

// Define the structure of a password
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Define the array of passwords
Password passwords[MAX_PASSWORDS];

// Get a password from the user
void get_password(char *username, char *password) {
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
}

// Add a password to the array
void add_password(char *username, char *password) {
    // Find an empty slot in the array
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].username[0] == '\0') {
            break;
        }
    }

    // If there is no empty slot, then the array is full
    if (i == MAX_PASSWORDS) {
        printf("The password array is full.\n");
        return;
    }

    // Copy the username and password into the array
    strcpy(passwords[i].username, username);
    strcpy(passwords[i].password, password);
}

// Delete a password from the array
void delete_password(char *username) {
    // Find the password in the array
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    // If the password was not found, then it does not exist
    if (i == MAX_PASSWORDS) {
        printf("The password does not exist.\n");
        return;
    }

    // Clear the password from the array
    passwords[i].username[0] = '\0';
    passwords[i].password[0] = '\0';
}

// Print the passwords in the array
void print_passwords() {
    // Iterate over the array
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        // Print the username and password
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Main function
int main() {
    // Get a password from the user
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    get_password(username, password);

    // Add the password to the array
    add_password(username, password);

    // Print the passwords in the array
    print_passwords();

    // Delete the password from the array
    delete_password(username);

    // Print the passwords in the array
    print_passwords();

    return 0;
}