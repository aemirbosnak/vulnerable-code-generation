//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char title[50];
    char content[1000];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void add_entry() {
    Entry new_entry;

    printf("Enter the title of your entry: ");
    scanf("%s", new_entry.title);

    printf("Enter the content of your entry: ");
    scanf("%[^\n]%*c", new_entry.content);

    new_entry.timestamp = time(NULL);

    int i = 0;
    for (; entries[i].timestamp != -1 && i < MAX_ENTRIES; i++) {}

    entries[i] = new_entry;

    entries[i].timestamp = -1;
}

void display_entries() {
    int i = 0;
    for (; entries[i].timestamp != -1 && i < MAX_ENTRIES; i++) {
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Timestamp: %s\n", ctime(entries[i].timestamp));
        printf("\n");
    }
}

int main() {
    int choice = 0;

    printf("Welcome to the Digital Diary!\n");

    while (choice != 3) {
        printf("Please select an option:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}