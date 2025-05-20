//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} Entry;

int compare(const void *a, const void *b) {
    Entry *entryA = (Entry *)a;
    Entry *entryB = (Entry *)b;
    return strcmp(entryA->name, entryB->name);
}

void addEntry(Entry *entries[], int *numEntries) {
    char name[50];
    char number[15];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", number);
    strcpy(entries[*numEntries]->name, name);
    strcpy(entries[*numEntries]->number, number);
    (*numEntries)++;
}

void searchEntry(Entry *entries, int numEntries, char *name) {
    Entry *result = bsearch(name, entries, numEntries, sizeof(Entry), compare);
    if (result!= NULL) {
        printf("Name: %s\nPhone number: %s\n", result->name, result->number);
    } else {
        printf("No entry found.\n");
    }
}

int main() {
    Entry *entries[MAX_ENTRIES];
    int numEntries = 0;

    while (numEntries < MAX_ENTRIES &&!feof(stdin)) {
        char choice;
        printf("\n1. Add entry\n2. Search entry\n3. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addEntry(entries, &numEntries);
                break;
            case '2':
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                searchEntry(entries, numEntries, name);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}