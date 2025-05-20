//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char key[MAX_SIZE];
    int value;
} IndexEntry;

IndexEntry entries[MAX_SIZE];
int numEntries = 0;

void insert(char* key, int value) {
    IndexEntry entry;
    strcpy(entry.key, key);
    entry.value = value;

    if (numEntries == MAX_SIZE) {
        printf("Database is full. Cannot insert more entries.\n");
        return;
    }

    entries[numEntries] = entry;
    numEntries++;
}

void delete(char* key) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            break;
        }
    }

    if (i == numEntries) {
        printf("Entry not found.\n");
        return;
    }

    for (int j = i; j < numEntries - 1; j++) {
        entries[j] = entries[j + 1];
    }

    numEntries--;
}

int search(char* key) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            return entries[i].value;
        }
    }

    return -1;
}

int main() {
    int choice;

    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", entries[numEntries].key);
                printf("Enter value: ");
                scanf("%d", &entries[numEntries].value);
                insert(entries[numEntries].key, entries[numEntries].value);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%s", entries[numEntries].key);
                delete(entries[numEntries].key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%s", entries[numEntries].key);
                printf("Value found: %d\n", search(entries[numEntries].key));
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 4);

    return 0;
}