//Code Llama-13B DATASET v1.0 Category: Password management ; Style: happy
/*
 * Password Management Example Program
 * By: [Your Name]
 * Description: This program allows users to manage their passwords securely.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store password information
struct Password {
    char *name;
    char *username;
    char *password;
};

// Function to create a new password
struct Password *create_password(char *name, char *username, char *password) {
    struct Password *new_password = malloc(sizeof(struct Password));
    new_password->name = strdup(name);
    new_password->username = strdup(username);
    new_password->password = strdup(password);
    return new_password;
}

// Function to delete a password
void delete_password(struct Password *password) {
    free(password->name);
    free(password->username);
    free(password->password);
    free(password);
}

// Function to store passwords in a file
void store_passwords(struct Password *passwords[], int num_passwords) {
    FILE *fp = fopen("passwords.txt", "w");
    for (int i = 0; i < num_passwords; i++) {
        fprintf(fp, "%s\n", passwords[i]->name);
        fprintf(fp, "%s\n", passwords[i]->username);
        fprintf(fp, "%s\n", passwords[i]->password);
    }
    fclose(fp);
}

// Function to retrieve passwords from a file
void retrieve_passwords(struct Password *passwords[], int *num_passwords) {
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        struct Password *password = create_password(line, line, line);
        passwords[*num_passwords] = password;
        *num_passwords += 1;
    }
    fclose(fp);
}

int main() {
    // Create a new password
    struct Password *password = create_password("Google", "johndoe", "password123");

    // Store the password in a file
    store_passwords(&password, 1);

    // Retrieve the password from the file
    struct Password *retrieved_passwords[100];
    int num_retrieved_passwords = 0;
    retrieve_passwords(retrieved_passwords, &num_retrieved_passwords);

    // Print the retrieved password
    for (int i = 0; i < num_retrieved_passwords; i++) {
        printf("%s\n", retrieved_passwords[i]->name);
        printf("%s\n", retrieved_passwords[i]->username);
        printf("%s\n", retrieved_passwords[i]->password);
    }

    // Delete the password
    delete_password(password);

    return 0;
}