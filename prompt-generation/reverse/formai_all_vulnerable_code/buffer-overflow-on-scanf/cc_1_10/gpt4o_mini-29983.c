//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LEN 256
#define FILE_NAME "diary_entries.txt"

typedef struct {
    char entry[ENTRY_LEN];
} DiaryEntry;

void addEntry();
void viewEntries();
void deleteEntry();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add a Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Delete a Diary Entry\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    DiaryEntry newEntry;
    printf("Enter your diary entry (max 255 characters): ");
    fgets(newEntry.entry, ENTRY_LEN, stdin);
    // Remove newline character if present
    newEntry.entry[strcspn(newEntry.entry, "\n")] = 0;

    fprintf(file, "%s\n", newEntry.entry);
    fclose(file);

    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    char line[ENTRY_LEN];
    printf("\n=== Your Diary Entries ===\n");
    int entryCount = 0;
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", ++entryCount, line);
    }
    if (entryCount == 0) {
        printf("No diary entries found.\n");
    }
    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    DiaryEntry entries[MAX_ENTRIES];
    int entryCount = 0;

    while (fgets(entries[entryCount].entry, sizeof(entries[entryCount].entry), file)) {
        entryCount++;
    }
    fclose(file);

    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    viewEntries();
    int deleteIndex;
    printf("Enter the number of the entry to delete: ");
    scanf("%d", &deleteIndex);
    clearBuffer();

    if (deleteIndex < 1 || deleteIndex > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    FILE *tempFile = fopen("temp_file.txt", "w");
    for (int i = 0; i < entryCount; i++) {
        if (i != deleteIndex - 1) {
            fprintf(tempFile, "%s", entries[i].entry);
        }
    }
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp_file.txt", FILE_NAME);

    printf("Diary entry %d deleted successfully!\n", deleteIndex);
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}