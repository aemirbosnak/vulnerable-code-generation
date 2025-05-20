//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* new_entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    strncpy(entries[num_entries].entry, new_entry, MAX_ENTRY_LENGTH-1);
    entries[num_entries].entry[MAX_ENTRY_LENGTH-1] = '\0';
    entries[num_entries].timestamp = time(NULL);
    num_entries++;

    printf("Entry added:\n%s\n", new_entry);
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n%s\n", i+1, entries[i].entry);
        printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
    }
}

void main() {
    srand(time(NULL));

    int choice;
    char new_entry[MAX_ENTRY_LENGTH];

    printf("Welcome to the Digital Diary.\n");
    printf("In this post-apocalyptic world, your thoughts and memories are all that remain.\n");
    printf("Use this diary to record your experiences and feelings.\n\n");

    while (true) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your new entry:\n");
                scanf("%s", new_entry);
                add_entry(new_entry);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}