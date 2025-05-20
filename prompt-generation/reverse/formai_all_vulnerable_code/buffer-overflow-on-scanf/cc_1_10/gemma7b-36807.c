//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[20];
    char number[20];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = malloc(sizeof(Entry));
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    printf("Enter number: ");
    scanf("%s", newEntry->number);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void searchEntry(Entry* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Number: %s\n", head->number);
            break;
        } else {
            head = head->next;
        }
    }

    if (head == NULL) {
        printf("Entry not found.\n");
    }
}

int main() {
    Entry* head = NULL;

    while (1) {
        printf("Enter command (add, search, quit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            head = insertEntry(head);
        } else if (strcmp(command, "search") == 0) {
            char name[20];
            printf("Enter name: ");
            scanf("%s", name);
            searchEntry(head, name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}