//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 1000

typedef struct {
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

void deleteEntry() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Deleting %s...\n", name);
            numEntries--;
            break;
        }
    }
}

void searchEntry() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            break;
        }
    }
}

int main() {
    printf("Welcome to the phone book!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
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
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}