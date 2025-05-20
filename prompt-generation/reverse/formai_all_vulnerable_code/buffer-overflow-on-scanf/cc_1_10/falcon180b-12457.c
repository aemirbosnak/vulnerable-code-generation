//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries;

void addEntry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter the name: ");
    scanf("%s", name);

    printf("Enter the phone number: ");
    scanf("%s", number);

    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].number, number);

    numEntries++;
}

void searchEntry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name to search: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(phoneBook[j].name, phoneBook[j + 1].name);
                strcpy(phoneBook[j].number, phoneBook[j + 1].number);
            }
            numEntries--;
            return;
        }
    }

    printf("Entry not found.\n");
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