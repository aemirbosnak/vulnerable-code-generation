//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_INPUT 256

typedef struct {
    char date[20];
    char entry[MAX_INPUT];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void logCurrentTime(char *buff) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", t);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! No more entries can be added.\n");
        return;
    }

    char tempEntry[MAX_INPUT];
    char currentTime[20];
    logCurrentTime(currentTime);

    printf("Enter your diary entry (max %d characters): ", MAX_INPUT);
    fgets(tempEntry, MAX_INPUT, stdin);
    
    // Remove newline character
    tempEntry[strcspn(tempEntry, "\n")] = 0;

    strcpy(diary[entryCount].date, currentTime);
    strcpy(diary[entryCount].entry, tempEntry);
    entryCount++;

    printf("Entry added successfully at %s\n", currentTime);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void searchEntries() {
    char searchTerm[MAX_INPUT];
    printf("Enter the keyword to search: ");
    fgets(searchTerm, MAX_INPUT, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline character

    int found = 0;
    printf("\n--- Search Results for '%s' ---\n", searchTerm);
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, searchTerm) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n\n", diary[i].entry);
            found++;
        }
    }
    
    if (found == 0) {
        printf("No entries found containing '%s'.\n", searchTerm);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entryNum;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &entryNum);
    getchar(); // clear newline character

    if (entryNum < 1 || entryNum > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entryNum - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry %d deleted successfully.\n", entryNum);
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add an Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Delete an Entry\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline character

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
                printf("Exiting Digital Diary. Stay inspired!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}