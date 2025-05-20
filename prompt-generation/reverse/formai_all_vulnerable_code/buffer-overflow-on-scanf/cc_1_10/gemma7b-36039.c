//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[50];
    char content[200];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void add_entry() {
    Entry new_entry;

    printf("Enter title: ");
    fgets(new_entry.title, 50, stdin);

    printf("Enter content: ");
    fgets(new_entry.content, 200, stdin);

    new_entry.timestamp = time(NULL);

    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].title == NULL) {
            entries[i] = new_entry;
            break;
        }
    }
}

void list_entries() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].title) {
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Timestamp: %s\n", entries[i].timestamp);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("Enter 1 to add an entry, 2 to list entries, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                list_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}