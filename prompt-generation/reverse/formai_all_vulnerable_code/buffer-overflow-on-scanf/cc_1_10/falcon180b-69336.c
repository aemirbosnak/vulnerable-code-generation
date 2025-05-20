//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

int numEntries = 0;
Entry phoneBook[MAX_ENTRIES];

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", phoneBook[numEntries].number);

    numEntries++;
    printf("Entry added.\n");
}

void searchEntry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phoneBook[i].name, phoneBook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            memmove(&phoneBook[i], &phoneBook[i+1], (numEntries-i-1)*sizeof(Entry));
            numEntries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void printAllEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nPhone number: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Print all entries\n");
        printf("5. Exit\n");
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
                printAllEntries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}