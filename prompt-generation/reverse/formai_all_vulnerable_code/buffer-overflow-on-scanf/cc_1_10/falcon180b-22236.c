//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[numEntries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[numEntries].number);

    numEntries++;
    printf("Entry added successfully.\n");
}

void searchEntry() {
    printf("Enter name to search: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

void deleteEntry() {
    printf("Enter name to delete: ");
    char deleteName[MAX_NAME_LENGTH];
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
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

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}