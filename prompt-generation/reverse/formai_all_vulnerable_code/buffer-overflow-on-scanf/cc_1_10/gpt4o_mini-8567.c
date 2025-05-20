//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILENAME "diary.txt"

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function prototypes
void addEntry();
void viewEntries();
void saveEntries();
void loadEntries();
void clearInputBuffer();

int main() {
    int choice;

    // Load existing entries from file
    loadEntries();

    do {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Save Entries to File\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear the input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveEntries();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter today's date (DD/MM/YYYY): ");
    fgets(diary[entryCount].date, MAX_LENGTH, stdin);
    diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0;  // Remove newline

    printf("Write your diary entry: ");
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;  // Remove newline

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries to display.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("---------------------\n");
    }
}

void saveEntries() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Entry: %s\n", diary[i].entry);
        fprintf(file, "---------------------\n");
    }

    fclose(file);
    printf("Entries saved to %s successfully!\n", FILENAME);
}

void loadEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous entries found. Starting fresh.\n");
        return;
    }

    while (fgets(diary[entryCount].date, MAX_LENGTH, file) && 
           fgets(diary[entryCount].entry, MAX_LENGTH, file)) {
        // Process and clean the strings
        diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0;
        diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;  // Prevent overflow
    }

    fclose(file);
    printf("Loaded %d entries from %s.\n", entryCount, FILENAME);
}

void clearInputBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}