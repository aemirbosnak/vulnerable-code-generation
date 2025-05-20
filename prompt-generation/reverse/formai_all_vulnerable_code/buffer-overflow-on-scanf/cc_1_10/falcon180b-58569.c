//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

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

void deleteEntry() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf("%s", entries[numEntries - 1].name);

    for (int i = 0; i < numEntries - 1; i++) {
        strcpy(entries[i].name, entries[i + 1].name);
        strcpy(entries[i].number, entries[i + 1].number);
    }

    numEntries--;
}

void searchEntry() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to search: ");
    char searchName[MAX_NAME_LEN];
    scanf("%s", searchName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            deleteEntry();
            break;
        case 3:
            searchEntry();
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