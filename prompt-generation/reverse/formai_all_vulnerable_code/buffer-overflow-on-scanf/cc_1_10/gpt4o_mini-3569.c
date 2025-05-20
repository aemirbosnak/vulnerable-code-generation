//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define FILENAME "journal.txt"

typedef struct {
    int id;
    char content[ENTRY_SIZE];
} JournalEntry;

void displayMenu() {
    printf("====== Journal Application ======\n");
    printf("1. Add Journal Entry\n");
    printf("2. View All Entries\n");
    printf("3. Delete an Entry\n");
    printf("4. Exit\n");
    printf("=================================\n");
    printf("Choose an option: ");
}

void addEntry() {
    JournalEntry entry;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    printf("Enter your journal entry: ");
    getchar();  // to consume the leftover newline
    fgets(entry.content, ENTRY_SIZE, stdin);
    entry.id = ftell(file) / ENTRY_SIZE + 1;  // Calculate ID based on file position

    fprintf(file, "%d|%s", entry.id, entry.content);
    fclose(file);
    printf("Entry added successfully!\n");
}

void viewAllEntries() {
    JournalEntry entry;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("No entries found.\n");
        return;
    }

    printf("====== Journal Entries ======\n");
    while (fscanf(file, "%d|%[^\n]\n", &entry.id, entry.content) != EOF) {
        printf("Entry %d: %s\n", entry.id, entry.content);
    }
    fclose(file);
}

void deleteEntry() {
    int idToDelete;
    JournalEntry entry;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Could not open file.\n");
        return;
    }

    printf("Enter entry ID to delete: ");
    scanf("%d", &idToDelete);
    int found = 0;

    while (fscanf(file, "%d|%[^\n]\n", &entry.id, entry.content) != EOF) {
        if (entry.id != idToDelete) {
            fprintf(tempFile, "%d|%s", entry.id, entry.content);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME); // Remove the original file
    rename("temp.txt", FILENAME); // Rename temp file to original name

    if (found) {
        printf("Entry %d deleted successfully!\n", idToDelete);
    } else {
        printf("Entry %d not found.\n", idToDelete);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewAllEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting the Journal Application. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}