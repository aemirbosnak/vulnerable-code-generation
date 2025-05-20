//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Password storage is full!\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter the website name: ");
    scanf("%s", newEntry.website);
    printf("Enter the username: ");
    scanf("%s", newEntry.username);
    printf("Enter the password: ");
    scanf("%s", newEntry.password);

    entries[entryCount++] = newEntry;
    printf("Entry added successfully!\n");
}

void listEntries() {
    if (entryCount == 0) {
        printf("No entries found!\n");
        return;
    }
    
    printf("%-30s %-30s %-30s\n", "Website", "Username", "Password");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%-30s %-30s %-30s\n", entries[i].website, entries[i].username, entries[i].password);
    }
}

void deleteEntry() {
    char website[MAX_LENGTH];
    printf("Enter the website name to delete: ");
    scanf("%s", website);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                entries[j] = entries[j + 1];
            }
            entryCount--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

void updateEntry() {
    char website[MAX_LENGTH];
    printf("Enter the website name to update: ");
    scanf("%s", website);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            printf("Enter new username: ");
            scanf("%s", entries[i].username);
            printf("Enter new password: ");
            scanf("%s", entries[i].password);
            printf("Entry updated successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

void searchEntry() {
    char website[MAX_LENGTH];
    printf("Enter the website name to search: ");
    scanf("%s", website);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            printf("Website: %s\n", entries[i].website);
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);
            return;
        }
    }
    printf("Entry not found!\n");
}

void saveEntriesToFile() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s %s\n", entries[i].website, entries[i].username, entries[i].password);
    }
    fclose(file);
    printf("Entries saved to file successfully!\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No existing file found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%s %s %s", entries[entryCount].website, entries[entryCount].username, entries[entryCount].password) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum entries reached while loading from file!\n");
            break;
        }
    }
    fclose(file);
    printf("Entries loaded from file successfully!\n");
}

int main() {
    int choice;
   
    loadEntriesFromFile();

    do {
        printf("\nPassword Management System\n");
        printf("1. Add Entry\n");
        printf("2. List Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Update Entry\n");
        printf("5. Search Entry\n");
        printf("6. Save Entries to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                addEntry();
                break;
            case 2:
                listEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                updateEntry();
                break;
            case 5:
                searchEntry();
                break;
            case 6:
                saveEntriesToFile();
                break;
            case 7:
                saveEntriesToFile();
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}