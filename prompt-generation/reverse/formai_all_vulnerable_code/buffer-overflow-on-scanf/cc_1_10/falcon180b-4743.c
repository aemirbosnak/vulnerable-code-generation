//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);

    printf("Enter number: ");
    scanf("%s", phoneBook[numEntries].number);

    numEntries++;
}

void deleteEntry() {
    int index;

    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < numEntries) {
        for (int i = index; i < numEntries - 1; i++) {
            strcpy(phoneBook[i].name, phoneBook[i + 1].name);
            strcpy(phoneBook[i].number, phoneBook[i + 1].number);
        }
        numEntries--;
    } else {
        printf("Invalid index.\n");
    }
}

void searchEntry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");

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