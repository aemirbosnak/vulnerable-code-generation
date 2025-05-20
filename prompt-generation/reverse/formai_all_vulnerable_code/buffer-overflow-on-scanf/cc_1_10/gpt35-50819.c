//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Define Password struct
typedef struct {
    char *website;
    char *username;
    char *password;
} Password;

// Function to add a new password to the password manager
void add_password(Password **passwords, int *num_passwords) {
    char website[50];
    char username[50];
    char password[50];

    // Read in user input
    printf("Enter website name:\n");
    scanf("%s", website);
    printf("Enter username:\n");
    scanf("%s", username);
    printf("Enter password:\n");
    scanf("%s", password);

    // Allocate memory for new Password struct and copy user input into it
    Password *new_password = malloc(sizeof(Password));
    new_password->website = malloc(strlen(website) + 1);
    strcpy(new_password->website, website);
    new_password->username = malloc(strlen(username) + 1);
    strcpy(new_password->username, username);
    new_password->password = malloc(strlen(password) + 1);
    strcpy(new_password->password, password);

    // Add new password to password manager
    passwords[*num_passwords] = new_password;
    (*num_passwords)++;

    printf("Password added successfully!\n");
}

// Function to view all passwords in the password manager
void view_passwords(Password **passwords, int *num_passwords) {
    printf("Website\t\tUsername\t\tPassword\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < *num_passwords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i]->website, passwords[i]->username, passwords[i]->password);
    }
}

// Function to search for a password based on website name
void search_password(Password **passwords, int *num_passwords) {
    char website[50];
    printf("Enter website name to search for:\n");
    scanf("%s", website);

    int found = 0;
    Password *found_password = NULL;

    // Search through all passwords to find matching website name
    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i]->website, website) == 0) {
            found = 1;
            found_password = passwords[i];
            break;
        }
    }

    // If password is found, display it. Otherwise, display an error message
    if (found) {
        printf("Website:\t%s\n", found_password->website);
        printf("Username:\t%s\n", found_password->username);
        printf("Password:\t%s\n", found_password->password);
    } else {
        printf("Password not found for website %s.\n", website);
    }
}

int main() {
    Password *passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char option;

    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Quit\n");

        scanf(" %c", &option);

        switch (option) {
            case '1':
                add_password(passwords, &num_passwords);
                break;
            case '2':
                view_passwords(passwords, &num_passwords);
                break;
            case '3':
                search_password(passwords, &num_passwords);
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}