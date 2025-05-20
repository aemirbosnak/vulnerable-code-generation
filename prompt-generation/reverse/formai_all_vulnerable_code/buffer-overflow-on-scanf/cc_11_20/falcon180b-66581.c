//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of passwords
#define MAX_PASSWORDS 10

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 20

// Define the structure for a password
typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
} Password;

// Define the main function
int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    // Initialize the passwords array
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        strcpy(passwords[i].name, "");
        strcpy(passwords[i].value, "");
    }

    // Main loop
    while (1) {
        printf("\n");
        printf("Password Manager\n");
        printf("-----------------\n");
        printf("1. Add password\n");
        printf("2. Edit password\n");
        printf("3. Delete password\n");
        printf("4. View all passwords\n");
        printf("5. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Add password
            printf("Enter password name: ");
            scanf("%s", passwords[numPasswords].name);
            printf("Enter password value: ");
            scanf("%s", passwords[numPasswords].value);
            numPasswords++;
            break;

        case 2:
            // Edit password
            if (numPasswords == 0) {
                printf("No passwords to edit.\n");
            } else {
                printf("Enter password name to edit: ");
                scanf("%s", passwords[0].name);
            }
            break;

        case 3:
            // Delete password
            if (numPasswords == 0) {
                printf("No passwords to delete.\n");
            } else {
                printf("Enter password name to delete: ");
                scanf("%s", passwords[0].name);
            }
            break;

        case 4:
            // View all passwords
            for (int i = 0; i < numPasswords; i++) {
                printf("Name: %s\nValue: %s\n", passwords[i].name, passwords[i].value);
            }
            break;

        case 5:
            // Exit
            return 0;

        default:
            // Invalid choice
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}