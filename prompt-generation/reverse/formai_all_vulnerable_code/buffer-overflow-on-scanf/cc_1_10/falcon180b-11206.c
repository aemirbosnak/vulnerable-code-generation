//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Title: ");
    scanf("%s", entries[num_entries].title);

    printf("Content: ");
    fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
    entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';

    time(&entries[num_entries].timestamp);
    num_entries++;
}

void view_entries() {
    printf("Title\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].title, ctime(&entries[i].timestamp));
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Keyword: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].content, keyword)) {
            printf("%s\t%s\n", entries[i].title, ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");
    printf("Commands: add, view, search, exit\n");

    while (1) {
        char command[MAX_ENTRY_LENGTH];
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add_entry();
        } else if (strcmp(command, "view") == 0) {
            view_entries();
        } else if (strcmp(command, "search") == 0) {
            search_entries();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}