//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 50
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char number[15];
} Entry;

Entry roundTable[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char name[], char number[]) {
    if (numEntries >= MAX_ENTRIES) {
        printf("The Round Table is full, thou canst not add more.\n");
        return;
    }

    strcpy(roundTable[numEntries].name, name);
    strcpy(roundTable[numEntries].number, number);
    numEntries++;
}

void searchEntry(char name[]) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcmp(roundTable[i].name, name) == 0) {
            printf("Thy search is complete, Sir %s can be reached at %s.\n", roundTable[i].name, roundTable[i].number);
            return;
        }
    }

    printf("Alas, the knight thou seeketh is not in the Round Table.\n");
}

int main() {
    char name[NAME_LENGTH], number[15];

    while (1) {
        printf("Welcome, noble knight, to the Royal Phonebook of King Arthur's Round Table. Thou mayest choose:\n");
        printf("1. Add a new entry\n");
        printf("2. Search for an entry\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the noble knight: ");
                scanf("%s", name);
                printf("Enter the number of the noble knight: ");
                scanf("%s", number);

                addEntry(name, number);
                break;

            case 2:
                printf("Enter the name of the noble knight thou seeketh: ");
                scanf("%s", name);

                searchEntry(name);
                break;

            case 3:
                printf("Farewell, noble knight.\n");
                return 0;

            default:
                printf("Thou hast entered an invalid choice.\n");
        }
    }
}