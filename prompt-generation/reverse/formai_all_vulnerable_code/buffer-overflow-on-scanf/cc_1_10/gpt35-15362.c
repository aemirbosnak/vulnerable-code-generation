//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a password entry
struct PasswordEntry {
    char website[50];
    char username[50];
    char password[50];
};

// Global array to hold password entries
struct PasswordEntry entries[100];
int numEntries = 0;

// Function to print all password entries
void printEntries() {
    printf("Website\t\t| Username\t| Password\n");
    printf("----------------------------------------\n");
    for(int i=0; i<numEntries; i++) {
        printf("%s\t| %s\t| %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

// Function to add a new password entry
void addEntry() {
    struct PasswordEntry entry;
    printf("Website: ");
    fgets(entry.website, 50, stdin);
    printf("Username: ");
    fgets(entry.username, 50, stdin);
    printf("Password: ");
    fgets(entry.password, 50, stdin);
    // Remove newline characters from input
    for(int i=0; i<50; i++) {
        if(entry.website[i] == '\n') {
            entry.website[i] = '\0';
        }
        if(entry.username[i] == '\n') {
            entry.username[i] = '\0';
        }
        if(entry.password[i] == '\n') {
            entry.password[i] = '\0';
        }
    }
    entries[numEntries++] = entry; // Add entry to array
}

// Function to update an existing password entry
void updateEntry() {
    char website[50];
    printf("Website of entry to update: ");
    fgets(website, 50, stdin);
    for(int i=0; i<numEntries; i++) {
        if(strcmp(entries[i].website, website) == 0) {
            printf("New username (press enter to keep old value): ");
            fgets(entries[i].username, 50, stdin);
            printf("New password (press enter to keep old value): ");
            fgets(entries[i].password, 50, stdin);
            // Remove newline characters from input
            for(int j=0; j<50; j++) {
                if(entries[i].username[j] == '\n') {
                    entries[i].username[j] = '\0';
                }
                if(entries[i].password[j] == '\n') {
                    entries[i].password[j] = '\0';
                }
            }
            printf("Entry updated.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

// Function to delete an existing password entry
void deleteEntry() {
    char website[50];
    printf("Website of entry to delete: ");
    fgets(website, 50, stdin);
    for(int i=0; i<numEntries; i++) {
        if(strcmp(entries[i].website, website) == 0) {
            for(int j=i+1; j<numEntries; j++) {
                // Shift entries after deleted entry to fill gap
                entries[j-1] = entries[j];
            }
            numEntries--;
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    // Print menu and loop until user chooses to exit
    char choice;
    do {
        printf("\n1. View password entries\n");
        printf("2. Add new password entry\n");
        printf("3. Update existing password entry\n");
        printf("4. Delete existing password entry\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%c", &choice);
        getchar(); // Consume newline character left over from scanf
        switch(choice) {
            case '1':
                printEntries();
                break;
            case '2':
                addEntry();
                break;
            case '3':
                updateEntry();
                break;
            case '4':
                deleteEntry();
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != '5');

    return 0;
}