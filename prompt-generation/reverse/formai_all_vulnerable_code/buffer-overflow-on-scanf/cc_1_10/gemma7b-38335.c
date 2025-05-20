//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char name[50];
    char date[30];
    char content[200];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = malloc(sizeof(Entry));
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    printf("Enter date: ");
    scanf("%s", newEntry->date);
    printf("Enter content: ");
    scanf("%s", newEntry->content);
    newEntry->next = head;
    return newEntry;
}

void printEntries(Entry* head) {
    Entry* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Date: %s\n", current->date);
        printf("Content: %s\n", current->content);
        printf("\n");
        current = current->next;
    }
}

int main() {
    Entry* head = NULL;
    int choice;

    printf("Press 1 to insert a new entry, 2 to print entries: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertEntry(head);
            break;
        case 2:
            printEntries(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}