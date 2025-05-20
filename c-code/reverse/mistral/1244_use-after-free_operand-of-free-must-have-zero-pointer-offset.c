#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct {
    char title[100];
    char content[500];
    int timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(const char* title, const char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(diary[num_entries].title, title);
    strcpy(diary[num_entries].content, content);
    diary[num_entries].timestamp = time(NULL);
    num_entries++;
}

void free_entries() {
    for (int i = 0; i < num_entries; i++) {
        free(diary[i].title);
        free(diary[i].content);
    }
    num_entries = 0;
}

int main() {
    char title[100];
    char content[500];

    for (int i = 0; i < 10; i++) {
        printf("Enter title: ");
        scanf("%s", title);
        printf("Enter content: ");
        scanf("%s", content);

        add_entry(title, content);

        if (i < 9) {
            printf("Freeing memory...\n");
            free(diary[i].title);
            free(diary[i].content);
        }
    }

    free_entries();

    // Use-after-free vulnerability demonstration
    for (int i = 0; i < 10; i++) {
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
    }

    return 0;
}
