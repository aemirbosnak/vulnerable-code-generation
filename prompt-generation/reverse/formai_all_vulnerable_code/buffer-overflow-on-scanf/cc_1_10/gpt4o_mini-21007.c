//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void getCurrentDate(char *dateStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateStr, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    char date[11];
    getCurrentDate(date);
    
    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH);
    getchar(); // Consume any leftover newline
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = '\0'; // Remove newline character

    strcpy(diary[entryCount].date, date);
    entryCount++;
    printf("Diary entry added on %s.\n", date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%d] %s: %s\n", i + 1, diary[i].date, diary[i].entry);
    }
    printf("---------------------\n");
}

void searchEntries() {
    char searchTerm[MAX_LENGTH];
    printf("Enter a keyword to search: ");
    getchar(); // Consume any leftover newline
    fgets(searchTerm, MAX_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Remove newline character

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, searchTerm) != NULL) {
            printf("[%d] %s: %s\n", i + 1, diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing the keyword \"%s\".\n", searchTerm);
    }
    printf("---------------------\n");
}

int main() {
    int choice;

    do {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");
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
                searchEntries();
                break;
            case 4:
                printf("Exiting the diary. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}