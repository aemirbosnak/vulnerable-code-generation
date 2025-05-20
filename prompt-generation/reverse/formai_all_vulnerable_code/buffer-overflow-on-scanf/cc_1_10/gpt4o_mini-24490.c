//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), 
             "%02d-%02d-%04d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);

    printf("Enter your diary entry:\n");
    fgets(diary[entryCount].entry, sizeof(diary[entryCount].entry), stdin);
    
    // Remove newline character from entry
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\nEntry: %s\n\n", diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the entry number to delete (1-%d): ", entryCount);
    scanf("%d", &index);
    getchar(); // Clear the newline character from input buffer

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully!\n");
}

void saveEntries() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary entries saved to diary.txt\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

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
                saveEntries();
                break;
            case 5:
                printf("Exiting the diary application. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}