//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1024

typedef struct {
    char *date;
    char *entry;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    if (num_entries >= MAX_ENTRIES) {
        fprintf(stderr, "Error: diary is full\n");
        return;
    }

    entries[num_entries].date = strdup(date);
    entries[num_entries].entry = strdup(entry);
    num_entries++;
}

void print_entry(DiaryEntry entry) {
    printf("Date: %s\n", entry.date);
    printf("Entry: %s\n\n", entry.entry);
}

void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }
}

void search_entries(char *keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            print_entry(entries[i]);
        }
    }
}

int main() {
    char input[MAX_ENTRY_SIZE];
    char command[MAX_ENTRY_SIZE];
    char *date;
    char *entry;

    while (1) {
        printf("Enter command (add, print, search, quit): ");
        fgets(input, MAX_ENTRY_SIZE, stdin);

        sscanf(input, "%s", command);

        if (!strcmp(command, "add")) {
            date = strtok(input, " ");
            entry = strtok(NULL, "");

            add_entry(date, entry);
        } else if (!strcmp(command, "print")) {
            print_all_entries();
        } else if (!strcmp(command, "search")) {
            char keyword[MAX_ENTRY_SIZE];

            printf("Enter keyword: ");
            fgets(keyword, MAX_ENTRY_SIZE, stdin);

            search_entries(keyword);
        } else if (!strcmp(command, "quit")) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}