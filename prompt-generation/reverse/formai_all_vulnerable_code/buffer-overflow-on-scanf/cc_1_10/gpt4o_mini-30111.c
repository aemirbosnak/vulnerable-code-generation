//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500
#define DATE_FORMAT "%Y-%m-%d %H:%M:%S"

// Structure to hold a diary entry
typedef struct {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function prototypes
void addEntry(DiaryEntry *entries, int *entryCount);
void viewEntries(DiaryEntry *entries, int entryCount);
void saveEntries(DiaryEntry *entries, int entryCount);
void loadEntries(DiaryEntry *entries, int *entryCount);
void displayMenu();

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    loadEntries(entries, &entryCount);

    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline character after number input

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
                printf("Exiting... Thank you for using the Digital Diary!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add a New Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Entries to File\n");
    printf("4. Exit\n");
}

void addEntry(DiaryEntry *entries, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(entries[*entryCount].date, sizeof(entries[*entryCount].date), DATE_FORMAT, tm_info);

    printf("Enter your diary entry (max %d characters): ", MAX_ENTRY_LENGTH);
    fgets(entries[*entryCount].content, MAX_ENTRY_LENGTH, stdin);
    entries[*entryCount].content[strcspn(entries[*entryCount].content, "\n")] = 0; // remove newline

    (*entryCount)++;
    printf("Entry added successfully!\n");
}

void viewEntries(DiaryEntry *entries, int entryCount) {
    if (entryCount == 0) {
        printf("No diary entries found!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d [%s]: %s\n", i + 1, entries[i].date, entries[i].content);
    }
}

void saveEntries(DiaryEntry *entries, int entryCount) {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Could not open file to save entries!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Entry %d [%s]: %s\n", i + 1, entries[i].date, entries[i].content);
    }
    fclose(file);
    printf("Entries saved successfully to diary_entries.txt!\n");
}

void loadEntries(DiaryEntry *entries, int *entryCount) {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No previous entries found, starting fresh!\n");
        return;
    }

    char line[MAX_ENTRY_LENGTH + 50];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Entry %d [%19[^]]]: %499[^\n]", 
                &(*entryCount), entries[*entryCount].date, entries[*entryCount].content) == 3) {
            (*entryCount)++;
        }
    }
    fclose(file);
    printf("Loaded %d previous entries.\n", *entryCount);
}