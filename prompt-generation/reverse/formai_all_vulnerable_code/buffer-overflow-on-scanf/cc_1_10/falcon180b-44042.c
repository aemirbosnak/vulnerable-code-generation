//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

void addEntry(Entry entries[], int numEntries) {
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", entries[numEntries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
    scanf("%s", entries[numEntries].number);

    numEntries++;
}

void searchEntry(Entry entries[], int numEntries, char *name) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void deleteEntry(Entry entries[], int numEntries, char *name) {
    int i, j;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            for (j = i; j < numEntries - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].number, entries[j + 1].number);
            }
            numEntries--;
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n2. Search Entry\n3. Delete Entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numEntries >= MAX_ENTRIES) {
                printf("Phone book is full.\n");
                break;
            }
            addEntry(entries, numEntries);
            numEntries++;
            break;
        case 2:
            printf("Enter name to search: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            searchEntry(entries, numEntries, name);
            break;
        case 3:
            printf("Enter name to delete: ");
            char delName[MAX_NAME_LENGTH];
            scanf("%s", delName);
            deleteEntry(entries, numEntries, delName);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}