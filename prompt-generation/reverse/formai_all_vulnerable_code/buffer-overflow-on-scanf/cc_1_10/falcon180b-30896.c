//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    int index;
} IndexEntry;

IndexEntry database[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("ERROR: Database is full.\n");
        return;
    }
    strcpy(database[numEntries].entry, entry);
    database[numEntries].index = numEntries;
    numEntries++;
}

void searchEntry(char* query) {
    int i = 0;
    while (i < numEntries) {
        if (strcmp(database[i].entry, query) == 0) {
            printf("Entry found: %s\n", query);
            printf("Index: %d\n", database[i].index);
            return;
        }
        i++;
    }
    printf("Entry not found.\n");
}

void main() {
    char input[MAX_ENTRY_LENGTH];
    char query[MAX_ENTRY_LENGTH];

    printf("Welcome to the Post-Apocalyptic Database System.\n");

    // Populate the database
    addEntry("Food");
    addEntry("Water");
    addEntry("Shelter");
    addEntry("Weapons");

    // Search the database
    printf("Enter a search query: ");
    scanf("%s", query);
    searchEntry(query);
}