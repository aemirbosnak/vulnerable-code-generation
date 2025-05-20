//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define NAME_LENGTH 50
#define NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} entry;

int main() {
    int choice;
    int numEntries = 0;
    entry phoneBook[MAX_ENTRIES];

    do {
        printf("Phone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display All Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numEntries == MAX_ENTRIES) {
                    printf("Phone book is full!\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", phoneBook[numEntries].name);
                    printf("Enter number: ");
                    scanf("%s", phoneBook[numEntries].number);
                    numEntries++;
                }
                break;
            case 2:
                printf("Enter name to search: ");
                char searchName[NAME_LENGTH];
                scanf("%s", searchName);
                int found = 0;

                for (int i = 0; i < numEntries; i++) {
                    if (strcmp(phoneBook[i].name, searchName) == 0) {
                        printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("Entry not found!\n");
                }
                break;
            case 3:
                printf("Phone Book:\n");
                for (int i = 0; i < numEntries; i++) {
                    printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}