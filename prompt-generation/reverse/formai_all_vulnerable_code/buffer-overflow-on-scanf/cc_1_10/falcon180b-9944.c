//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void add_entry(char* text) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    struct entry new_entry;
    strcpy(new_entry.text, text);
    new_entry.timestamp = time(NULL);

    entries[num_entries++] = new_entry;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Viewing %d entries:\n", num_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("%s (%s)\n", entries[i].text, ctime(&entries[i].timestamp));
    }
}

void search_entries(char* keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Searching for '%s'...\n", keyword);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].text, keyword)) {
            printf("%s (%s)\n", entries[i].text, ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Diary!\n");
    printf("Commands: add, view, search, quit\n");

    while (1) {
        char command[10];
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char text[MAX_ENTRY_LENGTH];
            printf("Enter diary entry: ");
            scanf("%s", text);

            add_entry(text);
        } else if (strcmp(command, "view") == 0) {
            view_entries();
        } else if (strcmp(command, "search") == 0) {
            char keyword[MAX_ENTRY_LENGTH];
            printf("Enter keyword to search: ");
            scanf("%s", keyword);

            search_entries(keyword);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}