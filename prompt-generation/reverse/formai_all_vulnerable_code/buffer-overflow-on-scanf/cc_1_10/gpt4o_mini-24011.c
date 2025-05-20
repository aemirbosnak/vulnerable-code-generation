//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();
void getCurrentDate(char *date, size_t size);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left after scanf

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
                printf("Exiting the diary program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
}

void getCurrentDate(char *date, size_t size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(date, size, "%04d-%02d-%02d %02d:%02d:%02d", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
             tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    fgets(diary[entryCount].entry, ENTRY_SIZE, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline

    getCurrentDate(diary[entryCount].date, sizeof(diary[entryCount].date));
    entryCount++;

    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found!\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d - Date: %s\n", i + 1, diary[i].date);
        printf("%s\n", diary[i].entry);
        printf("---------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No diary entries to delete!\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &index);
    getchar(); // consume the newline

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    entryCount--;

    printf("Entry %d deleted successfully!\n", index);
}