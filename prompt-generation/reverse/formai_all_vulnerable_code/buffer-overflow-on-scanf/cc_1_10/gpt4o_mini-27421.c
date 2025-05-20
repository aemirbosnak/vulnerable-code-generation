//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DATE_LENGTH 11
#define ENTRY_LENGTH 256

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

// Function to display the menu
void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("======================\n");
    printf("Choose an option: ");
}

// Function to add an entry
void addEntry() {
    if (entryCount < MAX_ENTRIES) {
        printf("Enter date (dd-mm-yyyy): ");
        fgets(diary[entryCount].date, DATE_LENGTH, stdin);
        diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0; // Remove newline

        printf("Write your diary entry:\n");
        fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
        diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline

        entryCount++;
        printf("Diary entry added successfully!\n");
    } else {
        printf("Diary is full! Cannot add more entries.\n");
    }
}

// Function to view entries
void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found!\n");
        return;
    }

    printf("\n=== Your Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. [%s] %s\n", i + 1, diary[i].date, diary[i].entry);
    }
    printf("==============================\n");
}

// Function to delete an entry
void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete!\n");
        return;
    }

    int entryNumber;
    viewEntries();
    printf("Enter the entry number to delete: ");
    scanf("%d", &entryNumber);
    getchar(); // Consume newline

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Diary entry deleted successfully!\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

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
                printf("Exiting the diary. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}