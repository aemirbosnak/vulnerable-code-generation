//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry(char* text) {
    if (entry_count >= MAX_ENTRIES) {
        printf("Error: Entry limit reached.\n");
        return;
    }
    time_t now = time(NULL);
    strncpy(entries[entry_count].text, text, MAX_ENTRY_LENGTH);
    entries[entry_count].timestamp = now;
    entry_count++;
}

void print_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s\n", entries[i].text);
    }
}

void search_entries(char* keyword) {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Searching for '%s'...\n", keyword);
    for (int i = 0; i < entry_count; i++) {
        if (strstr(entries[i].text, keyword)) {
            printf("%s\n", entries[i].text);
        }
    }
}

int main() {
    setbuf(stdout, NULL);
    printf("Welcome to the Digital Diary!\n");
    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Search entries\n");
        printf("0. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            char text[MAX_ENTRY_LENGTH];
            printf("Enter your entry: ");
            fgets(text, MAX_ENTRY_LENGTH, stdin);
            add_entry(text);
        } else if (choice == 2) {
            print_entries();
        } else if (choice == 3) {
            char keyword[MAX_ENTRY_LENGTH];
            printf("Enter keyword to search: ");
            fgets(keyword, MAX_ENTRY_LENGTH, stdin);
            search_entries(keyword);
        }
    }
    return 0;
}