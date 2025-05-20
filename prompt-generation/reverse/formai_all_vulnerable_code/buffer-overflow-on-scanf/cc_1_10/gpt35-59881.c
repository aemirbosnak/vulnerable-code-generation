//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

// Structs
struct Entry {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
};

// Functions
void addEntry(struct Entry *entries, int *numEntries) {
    // Get current date
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    char date[20];
    strftime(date, 20, "%Y-%m-%d %H:%M:%S", localTime);

    // Get entry content
    char content[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry: ");
    fgets(content, MAX_ENTRY_LENGTH, stdin);

    // Add entry to diary
    struct Entry newEntry = {0};
    strcpy(newEntry.date, date);
    strcpy(newEntry.content, content);
    entries[*numEntries] = newEntry;
    (*numEntries)++;

    printf("Entry added successfully!\n");
}

void viewEntries(struct Entry *entries, int numEntries) {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", entries[i].date);
        printf("%s\n", entries[i].content);
        printf("\n");
    }
}

// Main function
int main() {
    struct Entry diary[MAX_ENTRIES] = {0};
    int numEntries = 0;

    printf("Welcome to your digital diary.\n\n");

    while (1) {
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Quit\n\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                viewEntries(diary, numEntries);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}