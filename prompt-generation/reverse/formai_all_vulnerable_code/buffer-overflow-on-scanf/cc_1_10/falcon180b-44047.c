//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int numEntries = 0;
Entry entries[MAX_ENTRIES];

void addEntry(char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        exit(1);
    }

    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);

    numEntries++;
}

void displayEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");
    printf("--------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s\n%s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntries(char* keyword) {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Search results:\n");
    printf("--------------------\n");

    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s\n%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Digital Diary\n");
        printf("--------------------\n");

        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            addEntry(date, entry);
            break;

        case 2:
            displayEntries();
            break;

        case 3:
            printf("Enter keyword to search:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            searchEntries(entry);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}