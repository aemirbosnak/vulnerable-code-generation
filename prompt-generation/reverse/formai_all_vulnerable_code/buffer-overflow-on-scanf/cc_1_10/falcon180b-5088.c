//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_NUMBER_OF_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phonebook[MAX_NUMBER_OF_ENTRIES];
int numberOfEntries = 0;

void displayMenu() {
    printf("\nPhonebook Menu:\n");
    printf("1. Add new entry\n");
    printf("2. Search for entry\n");
    printf("3. Display all entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    Entry newEntry;
    strcpy(newEntry.name, "");
    strcpy(newEntry.number, "");

    int nameLength = 0;
    int numberLength = 0;

    printf("Enter name: ");
    scanf("%s", newEntry.name);
    nameLength = strlen(newEntry.name);

    if (nameLength > MAX_NAME_LENGTH) {
        printf("Name is too long.\n");
        return;
    }

    printf("Enter number: ");
    scanf("%s", newEntry.number);
    numberLength = strlen(newEntry.number);

    if (numberLength > MAX_NUMBER_LENGTH) {
        printf("Number is too long.\n");
        return;
    }

    if (numberOfEntries >= MAX_NUMBER_OF_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    strcpy(phonebook[numberOfEntries].name, newEntry.name);
    strcpy(phonebook[numberOfEntries].number, newEntry.number);

    numberOfEntries++;

    printf("Entry added successfully.\n");
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numberOfEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
        }
    }
}

void displayAllEntries() {
    for (int i = 0; i < numberOfEntries; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Number: %s\n", phonebook[i].number);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            searchEntry();
            break;
        case 3:
            displayAllEntries();
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