//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", phonebook[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[numEntries].number);

    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].number);
            break;
        }
    }
}

void deleteEntry() {
    printf("Enter name to delete: ");
    char searchName[MAX_NAME_LENGTH];
    scanf("%s", searchName);

    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            printf("Entry deleted.\n");
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}