//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

void add_entry(entry_t entries[], int num_entries, char* date, char* entry) {
    if (num_entries == MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries(entry_t entries[], int num_entries) {
    printf("Digital Diary:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(entry_t entries[], int num_entries, char* keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to your Digital Diary!\n");

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Search entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char date[20];
                time_t now = time(NULL);
                strftime(date, 20, "%Y-%m-%d", localtime(&now));

                char entry[MAX_ENTRY_LENGTH];
                printf("Enter your entry:\n");
                scanf("%[^\n]", entry);

                add_entry(entries, num_entries, date, entry);
                break;
            }
            case 2: {
                display_entries(entries, num_entries);
                break;
            }
            case 3: {
                char keyword[MAX_ENTRY_LENGTH];
                printf("Enter keyword to search:\n");
                scanf("%[^\n]", keyword);

                search_entries(entries, num_entries, keyword);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}