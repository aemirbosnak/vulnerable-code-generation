//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", entries[num_entries].title);

    printf("Enter content: ");
    fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
    entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';

    time_t now = time(NULL);
    entries[num_entries].timestamp = now;

    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Title\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].title, ctime(&entries[i].timestamp));
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword: ");
    scanf("%s", keyword);

    int matches = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].content, keyword)) {
            printf("Match found in entry %d:\n", i+1);
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("\n");

        int choice = rand() % 4 + 1;
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
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}