//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define DATE_LENGTH 20

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void deleteEntry();
void displayInstructions();

int main() {
    int choice;
    while (1) {
        displayInstructions();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // clear newline from buffer

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
                printf("Exiting the diary. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entryCount].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("Enter your diary entry for %s:\n", diary[entryCount].date);
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
    
    // Remove newline character at the end of string
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; 

    entryCount++;
    printf("Entry added successfully for %s!\n", diary[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("Your Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("-------------------------\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the entry to delete (0 to %d): ", entryCount - 1);
    scanf("%d", &index);
    getchar(); // clear newline from buffer

    if (index < 0 || index >= entryCount) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    for (int i = index; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully!\n");
}

void displayInstructions() {
    printf("\n**************************************\n");
    printf("            Digital Diary             \n");
    printf("**************************************\n");
    printf("1. Add new Entry\n");
    printf("2. View all Entries\n");
    printf("3. Delete an Entry\n");
    printf("4. Exit\n");
    printf("**************************************\n");
}