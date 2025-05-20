#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct {
    char title[100];
    char content[200];
} DiaryEntry;

DiaryEntry *entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *title, char *content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }
    entries[num_entries] = (DiaryEntry *)malloc(sizeof(DiaryEntry));
    strcpy(entries[num_entries]->title, title);
    strcpy(entries[num_entries]->content, content);
    num_entries++;
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Title: %s\nContent: %s\n", entries[i]->title, entries[i]->content);
    }
    for (int i = num_entries; i < MAX_ENTRIES; i++) {
        free(entries[i]);
    }
    num_entries = 0;
}

int main() {
    char title[100];
    char content[200];

    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("Enter title: ");
        scanf("%s", title);
        printf("Enter content: ");
        scanf("%s", content);
        add_entry(title, content);
    }

    display_entries();

    return 0;
}
