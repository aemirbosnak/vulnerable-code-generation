//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 2048

typedef struct {
    char date[32];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[numEntries].date, date, 31);
    strncpy(entries[numEntries].entry, entry, MAX_ENTRY_LENGTH - 1);
    numEntries++;
}

void printEntries(void) {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntries(char* keyword) {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Search results:\n");
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    char date[32];

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("\nOptions:\n1. Add entry\n2. Print entries\n3. Search entries\n4. Exit\n");
        scanf("%d", &input[0]);

        switch (input[0]) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter entry:\n");
                fgets(input, MAX_ENTRY_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                addEntry(date, input);
                break;
            case 2:
                printEntries();
                break;
            case 3:
                printf("Enter keyword to search: ");
                scanf("%s", input);
                searchEntries(input);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}