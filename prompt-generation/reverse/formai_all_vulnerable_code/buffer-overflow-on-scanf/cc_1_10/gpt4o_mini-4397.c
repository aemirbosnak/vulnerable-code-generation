//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    time_t timestamp;
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n======== Digital Diary ========\n");
    printf("1. Add New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    getchar(); // clear newline
    fgets(diary[entryCount].content, MAX_LENGTH, stdin);
    
    diary[entryCount].timestamp = time(NULL);
    entryCount++;
    
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("\nEntry %d:\n", i + 1);
        printf("Date & Time: %s", ctime(&diary[i].timestamp));
        printf("Content: %s", diary[i].content);
    }
}

void searchEntry() {
    char searchTerm[MAX_LENGTH];
    int found = 0;

    printf("Enter keyword to search: ");
    getchar(); // clear newline
    fgets(searchTerm, MAX_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].content, searchTerm) != NULL) {
            printf("\nFound in Entry %d:\n", i + 1);
            printf("Date & Time: %s", ctime(&diary[i].timestamp));
            printf("Content: %s", diary[i].content);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found containing '%s'.\n", searchTerm);
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
                searchEntry();
                break;
            case 4:
                printf("Exiting Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}