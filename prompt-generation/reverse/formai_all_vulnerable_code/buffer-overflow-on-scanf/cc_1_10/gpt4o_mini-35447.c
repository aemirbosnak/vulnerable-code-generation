//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define DIARY_FILE "diary.txt"

typedef struct DiaryEntry {
    char content[ENTRY_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry *entries, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    getchar(); // Clear the newline character from previous input
    fgets(entries[*entryCount].content, ENTRY_LENGTH, stdin);
    entries[*entryCount].content[strcspn(entries[*entryCount].content, "\n")] = 0; // Remove newline
    (*entryCount)++;

    FILE *file = fopen(DIARY_FILE, "a");
    if (file) {
        fprintf(file, "%s\n", entries[*entryCount - 1].content);
        fclose(file);
    } else {
        printf("Could not open diary file for writing.\n");
    }

    printf("Entry added successfully!\n");
}

void viewEntries(DiaryEntry *entries, int entryCount) {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("Your Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d: %s\n", i + 1, entries[i].content);
    }
}

void deleteEntry(DiaryEntry *entries, int *entryCount) {
    if (*entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entryNumber;
    printf("Enter the entry number to delete: ");
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > *entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entryNumber - 1; i < *entryCount - 1; i++) {
        entries[i] = entries[i + 1]; // Shift entries forward
    }
    (*entryCount)--;

    // Rewrite the diary file to reflect deletions
    FILE *file = fopen(DIARY_FILE, "w");
    if (file) {
        for (int i = 0; i < *entryCount; i++) {
            fprintf(file, "%s\n", entries[i].content);
        }
        fclose(file);
    } else {
        printf("Could not open diary file for writing.\n");
    }

    printf("Entry deleted successfully!\n");
}

void loadEntries(DiaryEntry *entries, int *entryCount) {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("Could not open diary file for reading, starting a new diary.\n");
        return;
    }

    while (fgets(entries[*entryCount].content, ENTRY_LENGTH, file) && *entryCount < MAX_ENTRIES) {
        entries[*entryCount].content[strcspn(entries[*entryCount].content, "\n")] = 0; // Remove newline
        (*entryCount)++;
    }

    fclose(file);
}

void displayMenu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("---------------------\n");
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int entryCount = 0;

    loadEntries(entries, &entryCount);

    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                viewEntries(entries, entryCount);
                break;
            case 3:
                deleteEntry(entries, &entryCount);
                break;
            case 4:
                printf("Exiting the Digital Diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}