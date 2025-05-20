//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_SERVICE 50

typedef struct {
    char service[MAX_SERVICE];
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} Entry;

Entry passwordManager[MAX_ENTRIES];
int entryCount = 0;

// Function to add a new entry
void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Password manager is full! Cannot add more entries.\n");
        return;
    }

    Entry newEntry;
    printf("Enter the service name: ");
    scanf("%s", newEntry.service);
    printf("Enter the username: ");
    scanf("%s", newEntry.username);
    printf("Enter the password: ");
    scanf("%s", newEntry.password);

    passwordManager[entryCount++] = newEntry;
    printf("Entry added successfully.\n");
}

// Function to display all entries
void displayEntries() {
    if (entryCount == 0) {
        printf("No entries found in the password manager.\n");
        return;
    }
    
    printf("\n--- Password Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Service: %s\n", passwordManager[i].service);
        printf("Username: %s\n", passwordManager[i].username);
        printf("Password: %s\n", passwordManager[i].password);
        printf("-------------------------\n");
    }
}

// Function to find and delete an entry
void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries found to delete.\n");
        return;
    }

    char serviceToDelete[MAX_SERVICE];
    printf("Enter the service name to delete: ");
    scanf("%s", serviceToDelete);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordManager[i].service, serviceToDelete) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            entryCount--;
            printf("Entry for %s deleted successfully.\n", serviceToDelete);
            return;
        }
    }
    printf("Service '%s' not found in entries.\n", serviceToDelete);
}

// Function to search for an entry
void searchEntry() {
    if (entryCount == 0) {
        printf("No entries found to search.\n");
        return;
    }

    char serviceToSearch[MAX_SERVICE];
    printf("Enter the service name to search: ");
    scanf("%s", serviceToSearch);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordManager[i].service, serviceToSearch) == 0) {
            printf("Service: %s\n", passwordManager[i].service);
            printf("Username: %s\n", passwordManager[i].username);
            printf("Password: %s\n", passwordManager[i].password);
            return;
        }
    }
    printf("Service '%s' not found in entries.\n", serviceToSearch);
}

// Main menu function
void displayMenu() {
    int choice;
    do {
        printf("\n--- Password Manager Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Search Entry\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                searchEntry();
                break;
            case 5:
                printf("Exiting Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);
}

// Main function
int main() {
    printf("Welcome to the Password Manager!\n");
    displayMenu();
    return 0;
}