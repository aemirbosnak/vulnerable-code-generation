//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 1024

typedef struct {
    time_t date;
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void printMenu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("----------------------\n");
    printf("Choose an option: ");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    getchar(); // To consume newline from previous input
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    diary[entryCount].date = time(NULL);
    entryCount++;
    
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d (date: %s): %s", i + 1, ctime(&diary[i].date), diary[i].entry);
    }
    printf("----------------------\n");
}

void searchEntry() {
    char keyword[MAX_LENGTH];
    printf("Enter keyword to search: ");
    getchar(); // To consume newline from previous input
    fgets(keyword, MAX_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove trailing newline

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("Entry %d (date: %s): %s", i + 1, ctime(&diary[i].date), diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing the keyword '%s'.\n", keyword);
    }
    printf("----------------------\n");
}

int main() {
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}