//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Define the structure of a password
typedef struct {
    char *username;
    char *password;
} password_t;

// Create an array of passwords
password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

// Function to add a new password to the array
void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password array is full\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

// Function to remove a password from the array
void remove_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Invalid password index\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    num_passwords--;
}

// Function to search for a password by username
int search_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to display all passwords
void display_passwords() {
    printf("Passwords:\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s - %s\n", i + 1, passwords[i].username, passwords[i].password);
    }
}

// Main function
int main() {
    add_password("user1", "password1");
    add_password("user2", "password2");
    add_password("user3", "password3");

    display_passwords();

    int index = search_password("user2");
    if (index >= 0) {
        printf("Password for %s is: %s\n", passwords[index].username, passwords[index].password);
    } else {
        printf("Password not found\n");
    }

    remove_password(1);

    display_passwords();

    return 0;
}