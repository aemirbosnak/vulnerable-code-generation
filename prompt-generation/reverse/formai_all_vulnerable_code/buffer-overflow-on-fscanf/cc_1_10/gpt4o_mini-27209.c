//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum lengths for string input
#define MAX_ENTRY_LENGTH 256
#define MAX_DIARY_ENTRIES 100

// Structure to represent a Diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function prototypes
void addEntry(DiaryEntry diaryEntries[], int *entryCount);
void viewEntries(DiaryEntry diaryEntries[], int entryCount);
void saveEntriesToFile(DiaryEntry diaryEntries[], int entryCount, const char *filename);
void loadEntriesFromFile(DiaryEntry diaryEntries[], int *entryCount, const char *filename);

int main() {
    DiaryEntry diaryEntries[MAX_DIARY_ENTRIES];
    int entryCount = 0;
    char choice;
    const char *filename = "diary_entries.txt";

    // Load previously saved entries
    loadEntriesFromFile(diaryEntries, &entryCount, filename);

    while (1) {
        printf("\n Digital Diary Menu\n");
        printf("1. Add a new entry\n");
        printf("2. View entries\n");
        printf("3. Save and exit\n");
        printf("Choose an option (1-3): ");
        choice = getchar();
        getchar(); // Consume newline character

        switch (choice) {
            case '1':
                if (entryCount < MAX_DIARY_ENTRIES) {
                    addEntry(diaryEntries, &entryCount);
                } else {
                    printf("Diary is full! Please save or delete an entry.\n");
                }
                break;
            case '2':
                viewEntries(diaryEntries, entryCount);
                break;
            case '3':
                saveEntriesToFile(diaryEntries, entryCount, filename);
                printf("Entries saved. Exiting.\n");
                return 0;
            default:
                printf("Invalid option. Please select again.\n");
        }
    }

    return 0;
}

void addEntry(DiaryEntry diaryEntries[], int *entryCount) {
    printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_LENGTH - 1);
    fgets(diaryEntries[*entryCount].entry, MAX_ENTRY_LENGTH, stdin);
    diaryEntries[*entryCount].timestamp = time(NULL);
    (*entryCount)++;
    printf("Diary entry added!\n");
}

void viewEntries(DiaryEntry diaryEntries[], int entryCount) {
    if (entryCount == 0) {
        printf("No diary entries to display.\n");
        return;
    }
    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. [%s] %s", i + 1, ctime(&diaryEntries[i].timestamp), diaryEntries[i].entry);
    }
}

void saveEntriesToFile(DiaryEntry diaryEntries[], int entryCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving diary entries.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%ld\n%s", diaryEntries[i].timestamp, diaryEntries[i].entry);
    }
    fclose(file);
    printf("Diary entries saved successfully.\n");
}

void loadEntriesFromFile(DiaryEntry diaryEntries[], int *entryCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return; // No previous entries; simply return.
    }
    while (!feof(file) && *entryCount < MAX_DIARY_ENTRIES) {
        fscanf(file, "%ld\n", &diaryEntries[*entryCount].timestamp);
        fgets(diaryEntries[*entryCount].entry, MAX_ENTRY_LENGTH, file);
        diaryEntries[*entryCount].entry[strcspn(diaryEntries[*entryCount].entry, "\n")] = 0; // Remove newline
        (*entryCount)++;
    }
    fclose(file);
    printf("Diary entries loaded successfully.\n");
}