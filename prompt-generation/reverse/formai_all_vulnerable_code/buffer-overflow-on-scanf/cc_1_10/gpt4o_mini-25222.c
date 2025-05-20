//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

typedef struct {
    char content[MAX_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();

int main() {
    int choice = 0;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

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
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void addEntry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Failed to open diary file.\n");
        return;
    }

    DiaryEntry entry;
    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH - 1);
    fgets(entry.content, sizeof(entry.content), stdin);
    // Remove newline character if present
    entry.content[strcspn(entry.content, "\n")] = 0;

    fprintf(file, "%s\n", entry.content);
    fclose(file);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "No entries found in the diary.\n");
        return;
    }

    char line[MAX_LENGTH];
    printf("\n--- Diary Entries ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "No entries found in the diary.\n");
        return;
    }

    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    // Read all entries into memory
    while (fgets(entries[count].content, sizeof(entries[count].content), file) && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entryID;
    printf("Choose which entry to delete (1 to %d): ", count);
    scanf("%d", &entryID);
    getchar();  // Clear newline character from input buffer

    if (entryID < 1 || entryID > count) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to delete the selected one
    for (int i = entryID - 1; i < count - 1; i++) {
        strcpy(entries[i].content, entries[i + 1].content);
    }
    count--;

    // Rewrite the diary file without the deleted entry
    file = fopen(DIARY_FILE, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s", entries[i].content);
    }

    fclose(file);
    printf("Entry deleted successfully!\n");
}