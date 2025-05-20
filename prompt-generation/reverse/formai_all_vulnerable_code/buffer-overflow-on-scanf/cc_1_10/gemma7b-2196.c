//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
    char name[255];
    int index;
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    newEntry->index = time(NULL);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void searchEntry(Entry* head, char* name) {
    Entry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            printf("Index: %d\n", currentEntry->index);
            break;
        }
        currentEntry = currentEntry->next;
    }

    if (currentEntry == NULL) {
        printf("Entry not found.\n");
    }
}

int main() {
    Entry* head = NULL;

    // Insert entries
    head = insertEntry(head);
    insertEntry(head);
    insertEntry(head);

    // Search entries
    searchEntry(head, "John Doe");
    searchEntry(head, "Jane Doe");

    return 0;
}