//Code Llama-13B DATASET v1.0 Category: Password management ; Style: multivariable
/*
 * Password Management Program
 *
 * This program allows the user to create, read, update, and delete
 * passwords in a database.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store password information
typedef struct {
    char username[20];
    char password[20];
} Password;

// Function to create a new password
void createPassword(Password *p) {
    printf("Enter a username: ");
    scanf("%s", p->username);
    printf("Enter a password: ");
    scanf("%s", p->password);
}

// Function to read a password
void readPassword(Password *p) {
    printf("Enter a username: ");
    scanf("%s", p->username);
    printf("Enter a password: ");
    scanf("%s", p->password);
}

// Function to update a password
void updatePassword(Password *p) {
    printf("Enter a new password: ");
    scanf("%s", p->password);
}

// Function to delete a password
void deletePassword(Password *p) {
    printf("Enter a username: ");
    scanf("%s", p->username);
}

// Main function
int main() {
    Password p;
    char choice;

    while (1) {
        printf("Enter a choice (C/R/U/D): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'C':
                createPassword(&p);
                break;
            case 'R':
                readPassword(&p);
                break;
            case 'U':
                updatePassword(&p);
                break;
            case 'D':
                deletePassword(&p);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}