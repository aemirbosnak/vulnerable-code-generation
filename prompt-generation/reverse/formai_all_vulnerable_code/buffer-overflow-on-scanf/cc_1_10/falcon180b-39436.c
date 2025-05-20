//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(entries[numEntries].name, name);
    strcpy(entries[numEntries].number, number);

    numEntries++;
}

void deleteEntry() {
    int i;
    char name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            numEntries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void searchEntry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. Search Entry\n");
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