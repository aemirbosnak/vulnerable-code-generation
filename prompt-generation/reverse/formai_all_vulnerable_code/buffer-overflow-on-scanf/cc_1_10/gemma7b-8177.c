//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[50];
    char content[200];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
    Entry* newEntry = malloc(sizeof(Entry));
    printf("Enter title: ");
    scanf("%s", newEntry->title);
    printf("Enter content: ");
    scanf("%s", newEntry->content);
    newEntry->next = head;
    head = newEntry;
}

void listEntries() {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("Enter 1 to add an entry, 2 to list entries, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                listEntries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}