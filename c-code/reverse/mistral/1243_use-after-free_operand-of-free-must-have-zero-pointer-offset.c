#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct DiaryEntry {
    char title[100];
    char content[500];
} DiaryEntry;

DiaryEntry* create_entry() {
    DiaryEntry* entry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    if (!entry) {
        perror("Memory allocation failed");
        return NULL;
    }
    entry->title[0] = '\0';
    entry->content[0] = '\0';
    return entry;
}

void free_entry(DiaryEntry* entry) {
    free(entry);
}

void display_entries(DiaryEntry entries[], int count) {
    for (int i = 0; i < count; ++i) {
        printf("Title: %s\nContent: %s\n", entries[i].title, entries[i].content);
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    char choice;
    do {
        printf("Enter title (or 'q' to quit): ");
        scanf("%s", entries[count].title);

        if (strcmp(entries[count].title, "q") == 0) break;

        printf("Enter content: ");
        fgets(entries[count].content, sizeof(entries[count].content), stdin);

        ++count;
    } while (count < MAX_ENTRIES);

    printf("\nDiary Entries:\n");
    display_entries(entries, count);

    for (int i = 0; i < count; ++i) {
        free_entry(entries + i);
    }

    return 0;
}
