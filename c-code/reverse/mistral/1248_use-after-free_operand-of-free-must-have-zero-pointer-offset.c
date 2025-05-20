#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 200

struct DiaryEntry {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
};

int main() {
    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    for (int i = 0; i < MAX_ENTRIES && num_entries < MAX_ENTRIES; ++i) {
        printf("Enter title: ");
        scanf("%s", entries[i].title);
        printf("Enter content: ");
        scanf("%s", entries[i].content);

        if (strlen(entries[i].title) == 0 || strlen(entries[i].content) == 0)
            break;

        ++num_entries;
    }

    for (int i = 0; i < num_entries; ++i) {
        printf("\nTitle: %s\nContent: %s\n", entries[i].title, entries[i].content);
    }

    for (int i = 0; i < num_entries; ++i) {
        memset(entries[i].title, 0, MAX_TITLE_LENGTH);
        memset(entries[i].content, 0, MAX_CONTENT_LENGTH);
    }

    return 0;
}
