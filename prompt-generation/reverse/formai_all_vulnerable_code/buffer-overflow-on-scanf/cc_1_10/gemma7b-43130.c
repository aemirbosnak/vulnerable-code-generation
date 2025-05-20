//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char title[50];
    char content[200];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
    Entry newEntry;

    printf("Enter the title of your entry:");
    scanf("%s", newEntry.title);

    printf("Enter the content of your entry:");
    scanf("%s", newEntry.content);

    newEntry.timestamp = time(NULL);

    int i = 0;
    for (; entries[i].timestamp != NULL; i++) {}
    entries[i] = newEntry;

    printf("Entry added!\n");
}

void listEntries() {
    int i = 0;
    for (; entries[i].timestamp != NULL; i++) {
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Timestamp: %s\n", entries[i].timestamp);
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter 1 to add an entry, 2 to list entries, or 3 to quit:");
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