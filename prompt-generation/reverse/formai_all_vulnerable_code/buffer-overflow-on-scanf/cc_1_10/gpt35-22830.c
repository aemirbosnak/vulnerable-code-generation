//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100 // Maximum number of passwords allowed
#define MAX_LENGTH 20 // Maximum length of the password

// Password structure to store each password
typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

// Function prototypes
void addPassword(Password *passwords[], int *numPasswords);
void viewPasswords(Password *passwords[], int numPasswords);
void getPassword(Password *passwords[], int numPasswords, char *website);

int main() {

    Password *passwords[MAX_PASSWORDS]; // Array of password structures
    int numPasswords = 0; // Number of passwords currently stored

    int option;
    do {
        // Display menu
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Get password\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        // Get user input
        scanf("%d", &option);

        switch (option) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                viewPasswords(passwords, numPasswords);
                break;
            case 3: {
                char website[MAX_LENGTH];
                printf("Enter website: ");
                scanf("%s", website);
                getPassword(passwords, numPasswords, website);
                break;
            }
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 4);

    // Free memory used to store passwords
    for (int i = 0; i < numPasswords; i++) {
        free(passwords[i]);
    }

    return 0;
}

// Function to add a password to the password array
void addPassword(Password *passwords[], int *numPasswords) {

    // Check if maximum number of passwords has been reached
    if (*numPasswords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached. Could not add password.\n");
        return;
    }

    // Allocate memory for the new password structure
    Password *newPassword = (Password *) malloc(sizeof(Password));
    if (newPassword == NULL) {
        printf("Memory allocation error. Could not add password.\n");
        return;
    }

    // Get the website, username, and password from the user
    printf("Enter website: ");
    scanf("%s", newPassword->website);
    printf("Enter username: ");
    scanf("%s", newPassword->username);
    printf("Enter password: ");
    scanf("%s", newPassword->password);

    // Add the new password to the password array
    passwords[*numPasswords] = newPassword;
    (*numPasswords)++;

    printf("Password added successfully.\n");
}

// Function to view all passwords in the password array
void viewPasswords(Password *passwords[], int numPasswords) {

    // Check if any passwords have been added
    if (numPasswords == 0) {
        printf("No passwords have been added yet.\n");
        return;
    }

    printf("\nPasswords:\n");
    printf("Website\t\tUsername\tPassword\n");
    printf("=======\t\t========\t========\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i]->website, passwords[i]->username, passwords[i]->password);
    }
}

// Function to get a specific password from the password array
void getPassword(Password *passwords[], int numPasswords, char *website) {

    // Check if any passwords have been added
    if (numPasswords == 0) {
        printf("No passwords have been added yet.\n");
        return;
    }

    // Search for the password with the specified website
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i]->website, website) == 0) {
            printf("%s password:\nUsername: %s\nPassword: %s\n", website, passwords[i]->username, passwords[i]->password);
            return;
        }
    }

    printf("No password found for %s.\n", website);
}