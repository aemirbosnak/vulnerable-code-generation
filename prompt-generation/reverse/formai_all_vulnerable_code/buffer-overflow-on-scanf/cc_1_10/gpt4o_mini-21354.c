//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500
#define FILENAME "diary.txt"

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();
void clearBuffer();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        fflush(stdin); // Clear the input buffer
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: deleteEntry(); break;
            case 4: printf("Exiting the diary. Stay safe!\n"); return 0;
            default: printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addEntry() {
    DiaryEntry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    clearBuffer(); // Clear the input buffer before taking string input
    fgets(newEntry.date, sizeof(newEntry.date), stdin);
    newEntry.date[strcspn(newEntry.date, "\n")] = '\0'; // Remove newline character

    printf("Write your diary entry: ");
    fgets(newEntry.entry, sizeof(newEntry.entry), stdin);
    newEntry.entry[strcspn(newEntry.entry, "\n")] = '\0'; // Remove newline character

    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%s: %s\n", newEntry.date, newEntry.entry);
    fclose(file);
    
    printf("Your entry has been saved. Stay inspired!\n");
}

void viewEntries() {
    char line[MAX_LENGTH + 11]; // Space for date
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No diary entries found!\n");
        return;
    }

    printf("\n=== Your Diary Entries ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No entries to delete!\n");
        return;
    }

    // Displaying current entries number for deletion
    char entries[MAX_ENTRIES][MAX_LENGTH + 11];
    int entryCount = 0;

    printf("\n=== Current Diary Entries ===\n");
    while (fgets(entries[entryCount], sizeof(entries[entryCount]), file)) {
        printf("%d: %s", entryCount + 1, entries[entryCount]);
        entryCount++;
    }
    fclose(file);

    int entryNumber;
    printf("Enter the entry number to delete: ");
    clearBuffer();
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    // Rewriting the diary excluding the entry to delete
    file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        if (i != entryNumber - 1) { // Skip the chosen entry
            fprintf(file, "%s", entries[i]);
        }
    }
    fclose(file);

    printf("Entry number %d has been deleted. Remember the good times!\n", entryNumber);
}

void clearBuffer() {
    while (getchar() != '\n'); // Flush standard input
}