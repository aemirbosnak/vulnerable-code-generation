//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", phonebook[numEntries].name);

    printf("Enter number (max %d characters): ", MAX_NUMBER_LENGTH);
    scanf("%s", phonebook[numEntries].number);

    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

void deleteEntry() {
    char deleteName[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], (numEntries-i-1)*sizeof(Entry));
            numEntries--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    int choice;

    printf("Phonebook Menu:\n");
    printf("1. Add entry\n");
    printf("2. Search entry\n");
    printf("3. Delete entry\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter choice: ");
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
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}