//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char title[20];
    char content[1000];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    time_t t = time(NULL);
    strftime(newEntry->title, 20, "Entry %a %b %d %H:%M:%S", localtime(&t));

    printf("Enter title: ");
    scanf("%s", newEntry->title);

    printf("Enter content: ");
    scanf("%s", newEntry->content);

    newEntry->next = head;
    head = newEntry;

    return head;
}

void displayEntries(Entry* head) {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main() {
    Entry* head = NULL;

    // Insert entries
    head = insertEntry(head);
    insertEntry(head);
    insertEntry(head);

    // Display entries
    displayEntries(head);

    return 0;
}