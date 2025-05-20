//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char title[256];
    char content[2048];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->next = NULL;

    printf("Enter entry title: ");
    scanf("%s", newEntry->title);

    printf("Enter entry content: ");
    scanf("%s", newEntry->content);

    if (head == NULL) {
        head = newEntry;
    } else {
        Entry* currentEntry = head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
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

void main() {
    int choice;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("1. Add Entry\n");
        printf("2. List Entries\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                listEntries();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }
}