//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[numEntries].number);

    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry() {
    char deleteName[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, deleteName) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].number, entries[j + 1].number);
            }
            numEntries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

void viewEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    printf("Phone Book\n");

    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. View all entries\n0. Exit\n");
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
            deleteEntry();
            break;

        case 4:
            viewEntries();
            break;

        case 0:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}