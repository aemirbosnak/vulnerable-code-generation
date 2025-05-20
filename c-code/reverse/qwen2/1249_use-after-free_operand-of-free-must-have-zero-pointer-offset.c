#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char input[256];

    printf("Enter 'add' to add a new entry, 'show' to display all entries, or 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "add") == 0 && numEntries < MAX_ENTRIES) {
            printf("Enter title: ");
            fgets(entries[numEntries].title, sizeof(entries[numEntries].title), stdin);
            entries[numEntries].title[strcspn(entries[numEntries].title, "\n")] = '\0';
            printf("Enter content: ");
            fgets(entries[numEntries].content, sizeof(entries[numEntries].content), stdin);
            entries[numEntries].content[strcspn(entries[numEntries].content, "\n")] = '\0';
            numEntries++;
        } else if (strcmp(input, "show") == 0) {
            for (int i = 0; i < numEntries; i++) {
                printf("Title: %s\nContent: %s\n\n", entries[i].title, entries[i].content);
            }
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}
