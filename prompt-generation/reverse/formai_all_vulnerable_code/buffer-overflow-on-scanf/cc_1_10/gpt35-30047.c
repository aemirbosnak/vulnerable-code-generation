//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUM_LENGTH];
} PhoneEntry;

void addEntry(PhoneEntry *phoneBook, int *numEntries);
void searchEntry(PhoneEntry *phoneBook, int numEntries);
void removeEntry(PhoneEntry *phoneBook, int *numEntries);

int main() {
    PhoneEntry phoneBook[100];
    int numEntries = 0;

    int choice = 0;
    while (choice != 4) {
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Remove Entry\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(phoneBook, &numEntries);
                break;
            case 2:
                searchEntry(phoneBook, numEntries);
                break;
            case 3:
                removeEntry(phoneBook, &numEntries);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void addEntry(PhoneEntry *phoneBook, int *numEntries) {
    if (*numEntries == 100) {
        printf("Phone book is full.\n");
        return;
    }

    PhoneEntry newEntry;
    printf("Enter name: ");
    scanf("%s", newEntry.name);
    printf("Enter number: ");
    scanf("%s", newEntry.number);

    phoneBook[*numEntries] = newEntry;
    *numEntries = *numEntries + 1;

    printf("Entry added.\n");
}

void searchEntry(PhoneEntry *phoneBook, int numEntries) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Number: %s\n", phoneBook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void removeEntry(PhoneEntry *phoneBook, int *numEntries) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to remove: ");
    scanf("%s", name);

    int i, j;
    for (i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (j = i; j < (*numEntries - 1); j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            *numEntries = *numEntries - 1;
            printf("Entry removed.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}