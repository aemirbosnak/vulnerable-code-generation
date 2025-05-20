//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, the diary is full.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(entries[num_entries].date, sizeof(entries[num_entries].date), "%Y-%m-%d", tm);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void view_entries() {
    printf("---- Digital Diary ----\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    printf("---- Search Results ----\n");

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char buffer[MAX_ENTRY_LENGTH];

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Search for a keyword\n");
        printf("4. Exit\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your entry:\n");
            fgets(buffer, MAX_ENTRY_LENGTH, stdin);
            add_entry(buffer);
            break;

        case '2':
            view_entries();
            break;

        case '3':
            printf("Enter the keyword to search for:\n");
            fgets(buffer, MAX_ENTRY_LENGTH, stdin);
            search_entries(buffer);
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}