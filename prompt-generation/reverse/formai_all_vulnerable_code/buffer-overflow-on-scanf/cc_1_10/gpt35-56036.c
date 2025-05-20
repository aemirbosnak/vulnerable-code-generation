//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // Maximum number of passwords the program can manage

struct Password {
    char *name; // Name for the password (e.g. email, bank account)
    char *password; // Actual password for the name
};

void print_passwords(struct Password *passwords, int size); // Function to print the current passwords
void add_password(struct Password **passwords, int *size); // Function to add a new password
void delete_password(struct Password **passwords, int *size); // Function to delete a password

int main() {
    int size = 0; // Current number of passwords stored
    struct Password *passwords = (struct Password*) malloc(MAX_PASSWORDS * sizeof(struct Password)); // Allocating memory for the maximum number of passwords

    while (1) { // Infinite loop for user input
        printf("----------------------------\n");
        printf("Type 'list' to see passwords\nType 'new' to add a password\nType 'delete' to remove a password\nType 'exit' to quit\n");
        printf("----------------------------\n");
        char input[50];
        scanf("%s", input);

        if (strcmp(input, "list") == 0) { // User wants to see all passwords
            print_passwords(passwords, size);
        }

        else if (strcmp(input, "new") == 0) { // User wants to add a new password
            add_password(&passwords, &size);
        }

        else if (strcmp(input, "delete") == 0) { // User wants to delete an existing password
            delete_password(&passwords, &size);
        }

        else if (strcmp(input, "exit") == 0) { // User wants to quit the program
            free(passwords); // Freeing up allocated memory
            return 0;
        }

        else { // User entered an invalid command
            printf("Invalid command\n");
        }
    }

    return 0;
}

void print_passwords(struct Password *passwords, int size) {
    if (size == 0) { // No passwords are stored yet
        printf("No passwords\n");
        return;
    }

    printf("----------------------------\n");
    printf("Stored passwords:\n");
    for (int i = 0; i < size; i++) { // Looping through all stored passwords
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
    printf("----------------------------\n");
}

void add_password(struct Password **passwords, int *size) {
    if (*size == MAX_PASSWORDS) { // Maximum number of passwords already stored
        printf("Maximum number of passwords reached\n");
        return;
    }

    char name[50];
    char password[50];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    struct Password new_password = {name, password}; // Creating new password struct
    (*passwords)[(*size)++] = new_password; // Adding new password to array and updating size
}

void delete_password(struct Password **passwords, int *size) {
    if (*size == 0) { // No passwords are stored
        printf("No passwords to delete\n");
        return;
    }

    char name[50];

    printf("Enter name of password to delete: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < *size; i++) { // Finding index of the password to delete
        if (strcmp((*passwords)[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) { // Password with the provided name was not found
        printf("Password not found\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) { // Shifting passwords in the array to fill the gap
        (*passwords)[i] = (*passwords)[i + 1];
    }

    (*size)--; // Updating size of the array to exclude the deleted password
    printf("Deleted password\n");
}