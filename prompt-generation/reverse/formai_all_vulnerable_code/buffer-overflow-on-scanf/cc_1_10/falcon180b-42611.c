//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 200
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", phonebook[numEntries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[numEntries].number);

    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcasecmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
        }
    }

    if (!found) {
        printf("No entry found.\n");
    }
}

void deleteEntry() {
    printf("Enter name to delete: ");
    scanf("%s", phonebook[numEntries - 1].name);

    for (int i = 0; i < numEntries - 1; i++) {
        strcpy(phonebook[i].name, phonebook[i + 1].name);
        strcpy(phonebook[i].number, phonebook[i + 1].number);
    }

    numEntries--;
}

int main() {
    numEntries = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n2. Search Entry\n3. Delete Entry\n4. Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}