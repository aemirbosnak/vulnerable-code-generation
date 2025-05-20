//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char name[50];
    char text[200];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->next = NULL;

    // Get the entry name and text from the user
    printf("Enter the entry name: ");
    scanf("%s", newEntry->name);

    printf("Enter the entry text: ");
    scanf("%s", newEntry->text);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void printEntries(Entry* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Text: %s\n", head->text);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Entry* head = NULL;

    // Insert entries until the user decides to quit
    while (1) {
        printf("Enter 'q' to quit or any key to insert an entry: ");
        char input;
        scanf("%c", &input);

        if (input == 'q') {
            break;
        } else {
            head = insertEntry(head);
        }
    }

    // Print all entries
    printEntries(head);

    return 0;
}