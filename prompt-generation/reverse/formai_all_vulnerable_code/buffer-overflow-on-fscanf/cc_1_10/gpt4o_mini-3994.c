//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    // Get current date
    snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%04d-%02d-%02d", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH - 1);
    getchar(); // Clear buffer
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
  
    // Remove newline character if present
    size_t len = strlen(diary[entryCount].entry);
    if (len > 0 && diary[entryCount].entry[len - 1] == '\n') {
        diary[entryCount].entry[len - 1] = '\0';
    }

    entryCount++;
    printf("Entry added for date: %s\n", diary[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\nDiary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%s]: %s\n", diary[i].date, diary[i].entry);
    }
}

void saveEntriesToFile() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "[%s]: %s\n", diary[i].date, diary[i].entry);
    }

    fclose(file);
    printf("Diary entries saved to diary_entries.txt\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No previous diary entries found.\n");
        return;
    }

    while (fscanf(file, "[%10[^]]]: %[^\n]\n", diary[entryCount].date, diary[entryCount].entry) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Reached maximum entry limit. Further entries will not be loaded.\n");
            break;
        }
    }

    fclose(file);
    printf("Diary entries loaded. Total entries: %d\n", entryCount);
}

void showMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Entries to File\n");
    printf("4. Load Entries from File\n");
    printf("5. Exit\n");
    printf("==========================\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    loadEntriesFromFile();

    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveEntriesToFile();
                break;
            case 4:
                loadEntriesFromFile();
                break;
            case 5:
                printf("Exiting the Digital Diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}