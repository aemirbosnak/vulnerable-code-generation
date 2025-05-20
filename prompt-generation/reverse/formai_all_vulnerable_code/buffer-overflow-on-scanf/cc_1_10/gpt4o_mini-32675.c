//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 1024

typedef struct {
    char entry[ENTRY_LENGTH];
    time_t date;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("--------------------------\n");
    printf("Select an option: ");
}

void addEntry() {
    if (entryCount < MAX_ENTRIES) {
        printf("Enter your diary entry: ");
        getchar(); // to consume newline character
        fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
        diary[entryCount].date = time(NULL);
        entryCount++;
        printf("Diary entry added!\n");
    } else {
        printf("Diary is full! Cannot add more entries.\n");
    }
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries to display.\n");
        return;
    }
    
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d: %s", i + 1, diary[i].entry);
        printf("Date: %s", ctime(&diary[i].date));
    }
    printf("--------------------------\n");
}

void searchEntries() {
    char keyword[ENTRY_LENGTH];
    printf("Enter keyword to search for: ");
    getchar();
    fgets(keyword, ENTRY_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove newline character

    printf("\n--- Search Results ---\n");
    int found = 0;
    
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("Entry %d: %s", i + 1, diary[i].entry);
            printf("Date: %s", ctime(&diary[i].date));
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing the keyword: %s\n", keyword);
    }
    printf("--------------------------\n");
}

void deleteEntry() {
    int entryNumber;
    printf("Enter entry number to delete: ");
    scanf("%d", &entryNumber);
    
    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number! Please try again.\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;

    printf("Diary entry %d deleted!\n", entryNumber);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Exiting the diary...\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}