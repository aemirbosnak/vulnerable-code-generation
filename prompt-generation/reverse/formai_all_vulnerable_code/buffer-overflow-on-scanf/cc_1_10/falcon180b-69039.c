//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH-1);
    scanf("%s", entries[entryCount].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH-1);
    scanf("%s", entries[entryCount].number);

    entryCount++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", searchName);

    int matchFound = false;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            matchFound = true;
        }
    }

    if (!matchFound) {
        printf("No entry found.\n");
    }
}

void sortEntries() {
    for (int i = 0; i < entryCount-1; i++) {
        for (int j = i+1; j < entryCount; j++) {
            if (strcmp(entries[i].name, entries[j].name) > 0) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

int main() {
    printf("Phone Book\n");

    while (true) {
        printf("\n1. Add entry\n2. Search entry\n3. Sort entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                sortEntries();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}