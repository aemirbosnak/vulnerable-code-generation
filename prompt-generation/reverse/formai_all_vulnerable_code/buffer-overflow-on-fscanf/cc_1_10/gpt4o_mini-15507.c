//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordBook[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Password book is full!\n");
        return;
    }

    printf("Enter service name: ");
    scanf("%s", passwordBook[entryCount].service);
    printf("Enter username: ");
    scanf("%s", passwordBook[entryCount].username);
    printf("Enter password: ");
    scanf("%s", passwordBook[entryCount].password);
    entryCount++;

    printf("Password entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No password entries found!\n");
        return;
    }

    printf("\nStored Password Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Service: %s | Username: %s | Password: %s\n",
               passwordBook[i].service,
               passwordBook[i].username,
               passwordBook[i].password);
    }
}

void deleteEntry() {
    char service[MAX_LENGTH];
    printf("Enter the service name to delete: ");
    scanf("%s", service);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordBook[i].service, service) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                passwordBook[j] = passwordBook[j + 1];
            }
            entryCount--;
            printf("Password entry deleted successfully!\n");
            return;
        }
    }
    printf("Service not found!\n");
}

void saveEntriesToFile() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s,%s,%s\n", passwordBook[i].service, passwordBook[i].username, passwordBook[i].password);
    }
    fclose(file);
    printf("Entries saved to passwords.txt successfully!\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%[^\n]\n",
                  passwordBook[entryCount].service,
                  passwordBook[entryCount].username,
                  passwordBook[entryCount].password) == 3) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum entries reached while loading.\n");
            break;
        }
    }
    fclose(file);
    printf("Entries loaded from passwords.txt successfully!\n");
}

void displayMenu() {
    printf("\n--- Password Management System ---\n");
    printf("1. Add Password Entry\n");
    printf("2. View Password Entries\n");
    printf("3. Delete Password Entry\n");
    printf("4. Save Entries to File\n");
    printf("5. Load Entries from File\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    loadEntriesFromFile(); // Load existing entries on startup

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                saveEntriesToFile();
                break;
            case 5:
                loadEntriesFromFile();
                break;
            case 6:
                printf("Exiting the Password Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}