//Code Llama-13B DATASET v1.0 Category: Password management ; Style: automated
/*
 * Password Management Program
 *
 * This program allows the user to create and manage passwords for their accounts.
 * The user can add, remove, and update passwords, as well as generate a random password.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store password information
typedef struct {
    char *username;
    char *password;
} Password;

// Function to generate a random password
char *generate_password() {
    char *password = malloc(9);
    for (int i = 0; i < 8; i++) {
        password[i] = 'a' + rand() % 26;
    }
    password[8] = '\0';
    return password;
}

// Function to add a password
void add_password(Password *passwords, int *num_passwords, char *username, char *password) {
    passwords[*num_passwords].username = strdup(username);
    passwords[*num_passwords].password = strdup(password);
    (*num_passwords)++;
}

// Function to remove a password
void remove_password(Password *passwords, int *num_passwords, char *username) {
    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            for (int j = i; j < *num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            (*num_passwords)--;
            break;
        }
    }
}

// Function to update a password
void update_password(Password *passwords, int *num_passwords, char *username, char *password) {
    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].password);
            passwords[i].password = strdup(password);
            break;
        }
    }
}

// Function to print all passwords
void print_passwords(Password *passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    // Initialize passwords array
    int num_passwords = 0;
    Password *passwords = malloc(10 * sizeof(Password));

    // Add a password
    add_password(passwords, &num_passwords, "username1", "password1");

    // Remove a password
    remove_password(passwords, &num_passwords, "username1");

    // Update a password
    update_password(passwords, &num_passwords, "username2", "newpassword");

    // Print all passwords
    print_passwords(passwords, num_passwords);

    // Free memory
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }
    free(passwords);

    return 0;
}