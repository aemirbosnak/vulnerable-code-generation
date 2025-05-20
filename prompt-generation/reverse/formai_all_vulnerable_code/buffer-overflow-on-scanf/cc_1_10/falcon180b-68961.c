//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ENTRIES 100
#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 15

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} Entry;

int numEntries = 0;
Entry entries[MAX_NUM_ENTRIES];

void addEntry() {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);
    printf("Enter number: ");
    scanf("%s", entries[numEntries].number);
    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_SIZE];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("Number: %s\n", entries[i].number);
            return;
        }
    }
    printf("No entry found.\n");
}

int main() {
    printf("Phone Book\n");
    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}