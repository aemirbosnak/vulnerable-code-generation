//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    char service[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

Entry *entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void deleteEntry();
void updateEntry();
void clearScreen();
void showMenu();
void freeEntries();

int main() {
    int choice;
    
    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                updateEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                freeEntries();
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}

void showMenu() {
    clearScreen();
    printf("=== Password Manager ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Update Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Entry limit reached! Cannot add more entries.\n");
        return;
    }

    Entry *newEntry = (Entry*)malloc(sizeof(Entry));
    if (newEntry == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the service name: ");
    scanf("%s", newEntry->service);
    printf("Enter username: ");
    scanf("%s", newEntry->username);
    printf("Enter password: ");
    scanf("%s", newEntry->password);

    entries[entryCount++] = newEntry;
    printf("Entry added successfully!\n");
    getchar(); // To consume newline character
    printf("Press Enter to continue...");
    getchar();
}

void viewEntries() {
    clearScreen();
    printf("--- Stored Entries ---\n");
    
    if (entryCount == 0) {
        printf("No entries found.\n");
    } else {
        for (int i = 0; i < entryCount; i++) {
            printf("Entry %d:\n", i + 1);
            printf(" Service: %s\n", entries[i]->service);
            printf(" Username: %s\n", entries[i]->username);
            printf(" Password: %s\n", entries[i]->password);
            printf("---------------------\n");
        }
    }
    
    printf("Press Enter to continue...");
    getchar(); // To consume newline character
    getchar();
}

void updateEntry() {
    int index;
    viewEntries();
    printf("Enter the entry number to update: ");
    scanf("%d", &index);

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    Entry *entryToUpdate = entries[index - 1];
    printf("Updating Entry for %s\n", entryToUpdate->service);
    printf("Enter new username (or press Enter to keep current): ");
    char newUsername[50];
    getchar(); // To clear newline from previous input
    fgets(newUsername, sizeof(newUsername), stdin);
    if (strlen(newUsername) > 1) {
        newUsername[strcspn(newUsername, "\n")] = 0; // Remove newline
        strcpy(entryToUpdate->username, newUsername);
    }

    printf("Enter new password (or press Enter to keep current): ");
    char newPassword[MAX_PASSWORD_LENGTH];
    fgets(newPassword, sizeof(newPassword), stdin);
    if (strlen(newPassword) > 1) {
        newPassword[strcspn(newPassword, "\n")] = 0; // Remove newline
        strcpy(entryToUpdate->password, newPassword);
    }

    printf("Entry updated successfully!\n");
    printf("Press Enter to continue...");
    getchar();
}

void deleteEntry() {
    int index;
    viewEntries();
    printf("Enter the entry number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    free(entries[index - 1]);

    // Shift entries to fill the gap
    for (int i = index - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1];
    }
    entryCount--;

    printf("Entry deleted successfully!\n");
    printf("Press Enter to continue...");
    getchar();
}

void freeEntries() {
    for (int i = 0; i < entryCount; i++) {
        free(entries[i]);
    }
}