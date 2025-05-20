//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRY_SIZE 1000
#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    char dateStr[20];
    time_t now = time(NULL);
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", localtime(&now));

    printf("Enter your entry for %s:\n", dateStr);
    fgets(entries[numEntries].entry, MAX_ENTRY_SIZE, stdin);
    strcpy(entries[numEntries].date, dateStr);
    numEntries++;
}

void viewEntries() {
    printf("Date\tEntry\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntry() {
    char searchDate[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", searchDate);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, searchDate) == 0) {
            printf("Entry for %s:\n%s", searchDate, entries[i].entry);
            return;
        }
    }

    printf("No entry found for %s.\n", searchDate);
}

int main() {
    printf("Digital Diary\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entry\n4. Exit\n");
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
                searchEntry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}