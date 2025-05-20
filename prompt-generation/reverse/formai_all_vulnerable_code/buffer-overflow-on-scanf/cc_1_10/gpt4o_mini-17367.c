//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define DATE_SIZE 20

typedef struct {
    char date[DATE_SIZE];
    char entry[ENTRY_SIZE];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Unable to add new entry.\n");
        return;
    }

    printf("Enter your diary entry: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(diary[entryCount].entry, ENTRY_SIZE, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline

    // Get the current date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[entryCount].date, sizeof(diary[entryCount].date), "%Y-%m-%d %H:%M:%S", t);

    entryCount++;
    printf("Entry added on %s.\n", diary[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d (%s): %s\n", i + 1, diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    int index;
    viewEntries();
    printf("Enter the entry number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }

    entryCount--;
    printf("Entry %d deleted successfully.\n", index);
}

void saveEntriesToFile() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    
    fclose(file);
    printf("Diary entries saved to diary.txt.\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No existing diary file found. Starting fresh.\n");
        return;
    }
    
    while (fgets(diary[entryCount].date, DATE_SIZE, file) && fgets(diary[entryCount].entry, ENTRY_SIZE, file)) {
        diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0; // Remove newline
        diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline
        entryCount++;
    }

    fclose(file);
    printf("Diary entries loaded from diary.txt.\n");
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Entries to File\n");
    printf("5. Load Entries from File\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    loadEntriesFromFile();

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                saveEntriesToFile();
                break;
            case 5:
                loadEntriesFromFile();
                break;
            case 6:
                printf("Exiting the diary application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}