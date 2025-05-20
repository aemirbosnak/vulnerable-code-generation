//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PW_LENGTH 50 // maximum password length
#define MAX_ENTRIES 10 // maximum number of password entries

typedef struct {
    char website[50];
    char username[50];
    char password[50];
} PasswordEntry;

void printMenu() {
    printf("Password Management System\n");
    printf("1. Add Password Entry\n");
    printf("2. View Password Entry\n");
    printf("3. Edit Password Entry\n");
    printf("4. Delete Password Entry\n");
    printf("5. Exit\n");
}

int main() {
    PasswordEntry passwordEntries[MAX_ENTRIES];
    int numEntries = 0;

    while(true) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(numEntries >= MAX_ENTRIES) {
                printf("Maximum number of entries reached.\n");
                printf("Please delete some entries before adding new ones.\n");
                continue; // go back to main menu
            }

            printf("Adding Password Entry:\n");
            PasswordEntry newEntry;
            printf("Website: ");
            scanf("%s", newEntry.website);
            printf("Username: ");
            scanf("%s", newEntry.username);
            printf("Password: ");
            scanf("%s", newEntry.password);
            passwordEntries[numEntries++] = newEntry; // add to array
            printf("New entry added successfully!\n");
        }
        else if(choice == 2) {
            if(numEntries == 0) {
                printf("No password entries found.\n");
                continue; // go back to main menu
            }

            printf("Viewing Password Entries:\n");
            for(int i = 0; i < numEntries; i++) {
                printf("Entry %d:\n", i+1);
                printf("Website: %s\n", passwordEntries[i].website);
                printf("Username: %s\n", passwordEntries[i].username);
                printf("Password: %s\n", passwordEntries[i].password);
            }
        }
        else if(choice == 3) {
            if(numEntries == 0) {
                printf("No password entries found.\n");
                continue; // go back to main menu
            }

            printf("Editing Password Entry:\n");
            int entryIndex;
            printf("Enter the index of the entry to edit: ");
            scanf("%d", &entryIndex);
            entryIndex--; // adjust for 0-based indexing

            if(entryIndex < 0 || entryIndex >= numEntries) {
                printf("Invalid entry index.\n");
                continue; // go back to main menu
            }

            printf("Website: ");
            scanf("%s", passwordEntries[entryIndex].website);
            printf("Username: ");
            scanf("%s", passwordEntries[entryIndex].username);
            printf("Password: ");
            scanf("%s", passwordEntries[entryIndex].password);
            printf("Entry updated successfully!\n");
        }
        else if(choice == 4) {
            if(numEntries == 0) {
                printf("No password entries found.\n");
                continue; // go back to main menu
            }

            printf("Deleting Password Entry:\n");
            int entryIndex;
            printf("Enter the index of the entry to delete: ");
            scanf("%d", &entryIndex);
            entryIndex--; // adjust for 0-based indexing

            if(entryIndex < 0 || entryIndex >= numEntries) {
                printf("Invalid entry index.\n");
                continue; // go back to main menu
            }

            // shift entries to fill the gap
            for(int i = entryIndex; i < numEntries-1; i++) {
                passwordEntries[i] = passwordEntries[i+1];
            }

            numEntries--;
            printf("Entry deleted successfully!\n");
        }
        else if(choice == 5) {
            printf("Thank you for using the Password Management System!\n");
            break; // exit program
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}