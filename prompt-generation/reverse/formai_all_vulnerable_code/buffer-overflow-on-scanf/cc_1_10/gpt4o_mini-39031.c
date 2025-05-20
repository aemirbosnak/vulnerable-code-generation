//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 500
#define DIARY_FILE "diary_entries.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void addEntry(DiaryEntry *entries, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Can't add more entries.\n");
        return;
    }

    printf("Enter title: ");
    fgets(entries[*entryCount].title, MAX_TITLE_LENGTH, stdin);
    entries[*entryCount].title[strcspn(entries[*entryCount].title, "\n")] = 0; 
   
    printf("Enter content (max 500 characters): ");
    fgets(entries[*entryCount].content, MAX_CONTENT_LENGTH, stdin);
    entries[*entryCount].content[strcspn(entries[*entryCount].content, "\n")] = 0;

    (*entryCount)++;
    printf("Entry added successfully.\n");
}

void viewEntries(DiaryEntry *entries, int entryCount) {
    if (entryCount == 0) {
        printf("No entries yet.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d: %s\n", i + 1, entries[i].title);
        printf("Content: %s\n\n", entries[i].content);
    }
}

void saveEntries(DiaryEntry *entries, int entryCount) {
    FILE *file = fopen(DIARY_FILE, "w");
    if (!file) {
        perror("Failed to open diary file");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", entries[i].title, entries[i].content);
    }

    fclose(file);
    printf("All entries have been saved to %s.\n", DIARY_FILE);
}

void loadEntries(DiaryEntry *entries, int *entryCount) {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("No saved diary entries found. Starting fresh.\n");
        return;
    }

    while (fgets(entries[*entryCount].title, MAX_TITLE_LENGTH, file) &&
           fgets(entries[*entryCount].content, MAX_CONTENT_LENGTH, file)) {
        entries[*entryCount].title[strcspn(entries[*entryCount].title, "\n")] = 0;
        entries[*entryCount].content[strcspn(entries[*entryCount].content, "\n")] = 0;
        (*entryCount)++;
    }

    fclose(file);
    printf("Diary entries loaded successfully.\n");
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Save entries\n");
    printf("4. Load entries\n");
    printf("5. Exit\n");
    printf("======================\n");
    printf("Choose an option: ");
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    loadEntries(entries, &entryCount);

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                viewEntries(entries, entryCount);
                break;
            case 3:
                saveEntries(entries, entryCount);
                break;
            case 4:
                loadEntries(entries, &entryCount);
                break;
            case 5:
                printf("Exiting the diary. May your thoughts be well preserved.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}