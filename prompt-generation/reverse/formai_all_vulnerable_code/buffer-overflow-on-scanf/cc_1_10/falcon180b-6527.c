//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", entries[numEntries].date);

    printf("Enter the time (HH:MM:SS): ");
    scanf("%s", entries[numEntries].time);

    printf("Enter your entry:\n");
    fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    numEntries++;

    printf("Entry added successfully.\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Viewing entries...\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void searchEntries() {
    char keyword[MAX_ENTRY_LENGTH];

    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to Sherlock Holmes' Digital Diary!\n");

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
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
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}