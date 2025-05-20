//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024
#define DIARY_FILE "diary_entries.txt"

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry *diary, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    printf("Enter your diary entry:\n");
    getchar(); // clear newline from previous input
    fgets(diary[*entryCount].entry, MAX_ENTRY_LENGTH, stdin);
    
    // Remove newline character if present
    diary[*entryCount].entry[strcspn(diary[*entryCount].entry, "\n")] = 0;

    (*entryCount)++;
    printf("Entry added successfully!\n");
}

void saveEntries(DiaryEntry *diary, int entryCount) {
    FILE *file = fopen(DIARY_FILE, "a");
    if (!file) {
        printf("Error opening diary file!\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n", diary[i].entry);
    }
    
    fclose(file);
    printf("Entries saved to %s successfully!\n", DIARY_FILE);
}

void viewStatistics(DiaryEntry *diary, int entryCount) {
    if (entryCount == 0) {
        printf("No entries to display statistics.\n");
        return;
    }
    
    int totalLength = 0;
    int longestLength = 0;
    int longestEntryIndex = 0;

    for (int i = 0; i < entryCount; i++) {
        int length = strlen(diary[i].entry);
        totalLength += length;
        if (length > longestLength) {
            longestLength = length;
            longestEntryIndex = i;
        }
    }

    printf("Total Entries: %d\n", entryCount);
    printf("Average Length of Entries: %.2f characters\n", (float)totalLength / entryCount);
    printf("Longest Entry (%d characters): %s\n", longestLength, diary[longestEntryIndex].entry);
}

void displayEntries(DiaryEntry *diary, int entryCount) {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d: %s\n", i + 1, diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    do {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add New Entry\n");
        printf("2. View Entries\n");
        printf("3. View Statistics\n");
        printf("4. Save Entries to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &entryCount);
                break;
            case 2:
                displayEntries(diary, entryCount);
                break;
            case 3:
                viewStatistics(diary, entryCount);
                break;
            case 4:
                saveEntries(diary, entryCount);
                break;
            case 5:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}