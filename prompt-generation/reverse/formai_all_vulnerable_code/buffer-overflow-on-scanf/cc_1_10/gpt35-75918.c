//FormAI DATASET v1.0 Category: Digital Diary ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_DATE_LENGTH 20

struct DiaryEntry {
    char date[MAX_DATE_LENGTH];
    char content[MAX_ENTRY_LENGTH];
};

void printEntry(struct DiaryEntry entry) {
    printf("----------------------------------------\n");
    printf("Date: %s\n", entry.date);
    printf("Content: %s\n", entry.content);
    printf("----------------------------------------\n");
}

void writeEntry(struct DiaryEntry *entries, int numEntries) {
    char content[MAX_ENTRY_LENGTH];
    char date[MAX_DATE_LENGTH];

    printf("\nEnter the date in mm/dd/yyyy format: ");
    scanf("%s", date);

    printf("\nEnter your thoughts: ");
    getchar(); // remove any previous newline character in buffer
    fgets(content, MAX_ENTRY_LENGTH, stdin);

    // create the entry and add to the array
    struct DiaryEntry newEntry;
    strcpy(newEntry.date, date);
    strcpy(newEntry.content, content);
    entries[numEntries] = newEntry;

    printf("\nEntry added successfully!\n");
}

void readEntries(struct DiaryEntry *entries, int numEntries) {
    if (numEntries == 0) {
        printf("\nNo entries found.\n");
        return;
    }

    printf("\nDIARY ENTRIES\n");
    for (int i = 0; i < numEntries; i++) {
        printEntry(entries[i]);
    }
}

void searchByDate(struct DiaryEntry *entries, int numEntries) {
    char date[MAX_DATE_LENGTH];
    printf("\nEnter the date in mm/dd/yyyy format: ");
    scanf("%s", date);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printEntry(entries[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo entries found for that date.\n");
    }
}

void menu() {
    printf("\nDIGITAL DIARY\n");
    printf("1. Write an entry\n");
    printf("2. Read all entries\n");
    printf("3. Search for an entry by date\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

int main() {
    struct DiaryEntry entries[100];
    int numEntries = 0;
    int choice;

    srand(time(NULL));

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeEntry(entries, numEntries);
                numEntries++;
                break;
            case 2:
                readEntries(entries, numEntries);
                break;
            case 3:
                searchByDate(entries, numEntries);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}