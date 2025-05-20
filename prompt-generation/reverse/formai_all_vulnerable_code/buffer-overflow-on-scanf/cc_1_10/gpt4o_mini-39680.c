//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_PASSWORDS];
    int count;
} PasswordManager;

void initializeManager(PasswordManager *pm) {
    pm->count = 0;
}

void addEntry(PasswordManager *pm) {
    if (pm->count >= MAX_PASSWORDS) {
        printf("Password manager is full! Cannot add more entries.\n");
        return;
    }
    
    PasswordEntry newEntry;
    
    printf("Enter service name: ");
    scanf("%s", newEntry.service);
    
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    
    printf("Enter password: ");
    scanf("%s", newEntry.password);
    
    pm->entries[pm->count] = newEntry;
    pm->count++;
    
    printf("Entry added successfully!\n");
}

void listEntries(PasswordManager *pm) {
    if (pm->count == 0) {
        printf("No entries found!\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    for (int i = 0; i < pm->count; i++) {
        printf("Entry #%d:\n", i + 1);
        printf("  Service: %s\n", pm->entries[i].service);
        printf("  Username: %s\n", pm->entries[i].username);
        printf("  Password: %s\n", pm->entries[i].password);
    }
}

void searchEntry(PasswordManager *pm) {
    char service[MAX_LENGTH];
    printf("Enter the service name to search: ");
    scanf("%s", service);
    
    for (int i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].service, service) == 0) {
            printf("Entry found:\n");
            printf("  Service: %s\n", pm->entries[i].service);
            printf("  Username: %s\n", pm->entries[i].username);
            printf("  Password: %s\n", pm->entries[i].password);
            return;
        }
    }
    printf("No entry found for service: %s\n", service);
}

void deleteEntry(PasswordManager *pm) {
    char service[MAX_LENGTH];
    printf("Enter the service name to delete: ");
    scanf("%s", service);
    
    for (int i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].service, service) == 0) {
            // Shift entries left to remove the entry
            for (int j = i; j < pm->count - 1; j++) {
                pm->entries[j] = pm->entries[j + 1];
            }
            pm->count--;
            printf("Entry for service '%s' deleted successfully!\n", service);
            return;
        }
    }
    printf("No entry found for service: %s\n", service);
}

void saveEntriesToFile(PasswordManager *pm) {
    FILE *file = fopen("passwords.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < pm->count; i++) {
        fprintf(file, "%s %s %s\n", pm->entries[i].service, pm->entries[i].username, pm->entries[i].password);
    }
    
    fclose(file);
    printf("Entries saved to file successfully!\n");
}

void loadEntriesFromFile(PasswordManager *pm) {
    FILE *file = fopen("passwords.txt", "r");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }
    
    while (fscanf(file, "%s %s %s", pm->entries[pm->count].service, pm->entries[pm->count].username, pm->entries[pm->count].password) == 3) {
        pm->count++;
        if (pm->count >= MAX_PASSWORDS) {
            printf("Reached maximum password entry limit while loading from file.\n");
            break;
        }
    }

    fclose(file);
    printf("Entries loaded from file successfully!\n");
}

int main() {
    PasswordManager pm;
    initializeManager(&pm);
    loadEntriesFromFile(&pm);
    
    int choice;

    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Entry\n");
        printf("2. List Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Save Entries\n");
        printf("6. Load Entries\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEntry(&pm); break;
            case 2: listEntries(&pm); break;
            case 3: searchEntry(&pm); break;
            case 4: deleteEntry(&pm); break;
            case 5: saveEntriesToFile(&pm); break;
            case 6: loadEntriesFromFile(&pm); break;
            case 7: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    saveEntriesToFile(&pm); // Save to file on exit
    return 0;
}