//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 20
#define MAX_ENTRIES 1000

typedef struct entry {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strncpy(phonebook[numEntries].name, name, MAX_NAME_SIZE);
    strncpy(phonebook[numEntries].number, number, MAX_NUMBER_SIZE);

    numEntries++;
}

void searchEntry() {
    char name[MAX_NAME_SIZE];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry() {
    char name[MAX_NAME_SIZE];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                strncpy(phonebook[j].name, phonebook[j+1].name, MAX_NAME_SIZE);
                strncpy(phonebook[j].number, phonebook[j+1].number, MAX_NUMBER_SIZE);
            }

            numEntries--;
            break;
        }
    }
}

void printAllEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print all entries\n5. Exit\n");
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
                printAllEntries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}