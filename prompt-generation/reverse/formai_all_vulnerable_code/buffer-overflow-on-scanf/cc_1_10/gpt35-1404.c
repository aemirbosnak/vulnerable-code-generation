//FormAI DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
    int month;
    int day;
    int year;
    char entry[300];
};

void displayMenu() {
    printf("Welcome to Your Digital Diary!\n");
    printf("-----------------------------\n");
    printf("1. New Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n\n");
}

void addEntry(struct Entry *entryArray, int *entryCount) {
    int month, day, year;
    char entry[300];

    printf("Enter the date of your entry (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Enter your entry:\n");
    fflush(stdin);
    fgets(entry, 300, stdin);

    entryArray[*entryCount].month = month;
    entryArray[*entryCount].day = day;
    entryArray[*entryCount].year = year;
    strcpy(entryArray[*entryCount].entry, entry);

    (*entryCount)++;
    printf("\nEntry successfully added!\n\n");
}

void viewEntries(struct Entry *entryArray, int entryCount) {
    if (entryCount == 0) {
        printf("\nNo entries found.\n\n");
        return;
    }

    printf("\nEntries:\n");
    printf("--------\n");

    for (int i = 0; i < entryCount; i++) {
        printf("[%d] %02d/%02d/%d: %s\n", (i+1), entryArray[i].month, entryArray[i].day, entryArray[i].year, entryArray[i].entry);
    }

    printf("\n");
}

void searchEntries(struct Entry *entryArray, int entryCount) {
    if (entryCount == 0) {
        printf("\nNo entries found.\n\n");
        return;
    }

    char searchTerm[300];

    printf("\nEnter a word to search for in your entries: ");
    fflush(stdin);
    fgets(searchTerm, 300, stdin);

    int matchFound = 0;

    printf("\nMatching Entries:\n");
    printf("-----------------\n");

    for (int i = 0; i < entryCount; i++) {
        if (strstr(entryArray[i].entry, searchTerm) != NULL) {
            printf("[%d] %02d/%02d/%d: %s\n", (i+1), entryArray[i].month, entryArray[i].day, entryArray[i].year, entryArray[i].entry);
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("No entries matched your search term.\n");
    }

    printf("\n");
}

void exitProgram(int *exitFlag) {
    printf("\nGoodbye!\n");
    (*exitFlag) = 1;
}

int main() {
    struct Entry entryArray[100];
    int entryCount = 0;
    int exitFlag = 0;

    while (!exitFlag) {
        displayMenu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEntry(entryArray, &entryCount);
                    break;
            case 2: viewEntries(entryArray, entryCount);
                    break;
            case 3: searchEntries(entryArray, entryCount);
                    break;
            case 4: exitProgram(&exitFlag);
                    break;
            default: printf("\nInvalid choice, please try again.\n\n");
                     break;
        }
    }

    return 0;
}