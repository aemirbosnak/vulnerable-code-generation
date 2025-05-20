//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_CONTENT 512
#define MAX_DATE 20

typedef struct {
    char date[MAX_DATE];
    char content[MAX_CONTENT];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
    printf("======================\n");
    printf("Choose an option: ");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry for today (max %d characters): \n", MAX_CONTENT);
    getchar();  // clear the newline from previous input
    fgets(entries[entryCount].content, MAX_CONTENT, stdin);
    
    // Get the current date
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(entries[entryCount].date, MAX_DATE, "%Y-%m-%d", tm_info);

    entryCount++;
    printf("Entry added on %s\n", entries[entryCount-1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d (%s): %s", i + 1, entries[i].date, entries[i].content);
        printf("-------------------\n");
    }
}

void searchEntries() {
    char searchTerm[MAX_CONTENT];
    printf("Enter search term: ");
    getchar();  // clear newline from previous input
    fgets(searchTerm, MAX_CONTENT, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline character

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(entries[i].content, searchTerm) != NULL) {
            printf("Entry %d (%s): %s", i + 1, entries[i].date, entries[i].content);
            printf("-------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing the term: %s\n", searchTerm);
    }
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
                printf("Exiting the diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}