//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 100

// Structure to store password data
struct password {
    char name[30]; // Name of the password
    char username[30]; // Username for the password
    char password[30]; // Password value
};

int main() {
    // Initialize variables
    int menuChoice, numPasswords = 0, i;
    struct password passwords[MAX_PASSWORDS];
    char masterPassword[30] = "admin";

    while (1) {
        // Display menu
        printf("\n1. Add a new password");
        printf("\n2. View all passwords");
        printf("\n3. Delete a password");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                // Check if max number of passwords already reached
                if (numPasswords == MAX_PASSWORDS) {
                    printf("\nMaximum number of passwords reached!");
                    break;
                }

                // Get details for new password
                struct password newPassword;
                printf("\nEnter name of the password: ");
                scanf("%s", newPassword.name);
                printf("Enter username for the password: ");
                scanf("%s", newPassword.username);
                printf("Enter the password value: ");
                scanf("%s", newPassword.password);

                // Add new password to array
                passwords[numPasswords] = newPassword;
                numPasswords++;

                printf("\nPassword added successfully!\n");
                break;

            case 2:
                // Check if any passwords added yet
                if (numPasswords == 0) {
                    printf("\nNo passwords added yet!");
                    break;
                }

                printf("\n%-20s%-20s%-20s", "NAME", "USERNAME", "PASSWORD");
                printf("\n--------------------------------------------------------");
                for (i = 0; i < numPasswords; i++) {
                    printf("\n%-20s%-20s%-20s", passwords[i].name, passwords[i].username, passwords[i].password);
                }
                printf("\n");
                break;

            case 3:
                // Check if any passwords added yet
                if (numPasswords == 0) {
                    printf("\nNo passwords added yet!");
                    break;
                }

                // Prompt for password name to delete
                char nameToDelete[30];
                printf("\nEnter name of password to delete: ");
                scanf("%s", nameToDelete);

                // Search for the password to delete
                for (i = 0; i < numPasswords; i++) {
                    if (strcmp(passwords[i].name, nameToDelete) == 0) {
                        // Shift any passwords past this one to fill the gap
                        for (int j = i; j < numPasswords - 1; j++) {
                            passwords[j] = passwords[j+1];
                        }
                        numPasswords--;
                        printf("\nPassword deleted successfully!");
                        break;
                    }
                }

                // Print message if password not found
                if (i == numPasswords) {
                    printf("\nPassword not found!");
                }
                break;

            case 4:
                // Exit the program
                printf("\nAre you sure you want to exit? Enter master password to confirm: ");
                char inputPassword[30];
                scanf("%s", inputPassword);
                if (strcmp(inputPassword, masterPassword) == 0) {
                    printf("\nExiting program...");
                    exit(0);
                } else {
                    printf("\nIncorrect password!\n");
                }
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}