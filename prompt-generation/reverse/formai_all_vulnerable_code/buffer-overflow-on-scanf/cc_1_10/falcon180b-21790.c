//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct Entry {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
};

int entry_count = 0;
struct Entry entries[MAX_ENTRIES];

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    printf("Enter your diary entry:\n");
    fgets(entries[entry_count].text, MAX_ENTRY_LENGTH, stdin);

    time_t now = time(NULL);
    entries[entry_count].timestamp = now;

    entry_count++;
    printf("Entry added.\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d: %s\n", i+1, entries[i].text);
        printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
        printf("\n");
    }
}

void search_entries() {
    char search_text[MAX_ENTRY_LENGTH];
    printf("Enter search text: ");
    fgets(search_text, MAX_ENTRY_LENGTH, stdin);

    int count = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(entries[i].text, search_text)) {
            printf("Entry %d: %s\n", i+1, entries[i].text);
            printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
            printf("\n");
            count++;
        }
    }

    if (count == 0) {
        printf("No entries found.\n");
    }
}

int main() {
    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}