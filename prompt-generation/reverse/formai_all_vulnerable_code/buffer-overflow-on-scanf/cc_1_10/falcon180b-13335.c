//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void printEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", entries[i].entry);
    }
}

void addEntry(char* newEntry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }

    strcpy(entries[numEntries].entry, newEntry);
    time_t now = time(NULL);
    entries[numEntries].timestamp = now;
    numEntries++;
}

void searchEntries(char* searchTerm) {
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, searchTerm)!= NULL) {
            printf("%s\n", entries[i].entry);
        }
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    char searchTerm[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter your entry:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        addEntry(input);

        printf("Do you want to search for an entry? (y/n)\n");
        scanf("%s", searchTerm);

        if (strcmp(searchTerm, "y") == 0) {
            printf("Enter the search term:\n");
            scanf("%s", searchTerm);

            printf("Search results:\n");
            searchEntries(searchTerm);
        }
    }

    return 0;
}