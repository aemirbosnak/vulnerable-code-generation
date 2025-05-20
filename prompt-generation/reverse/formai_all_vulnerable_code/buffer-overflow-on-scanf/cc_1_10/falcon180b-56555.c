//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int numEntries = 0;
Entry entries[MAX_ENTRIES];

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    Entry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);

    printf("Enter entry:\n");
    fgets(newEntry.entry, MAX_ENTRY_LENGTH, stdin);
    newEntry.entry[strcspn(newEntry.entry, "\n")] = '\0';

    strcpy(entries[numEntries].date, newEntry.date);
    strcpy(entries[numEntries].entry, newEntry.entry);

    numEntries++;
    printf("Entry added.\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Date\tEntry\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntries() {
    char searchDate[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", searchDate);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, searchDate) == 0) {
            printf("%s\n%s\n", entries[i].date, entries[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found for the given date.\n");
    }
}

int main() {
    printf("Welcome to Digital Diary!\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
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
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}