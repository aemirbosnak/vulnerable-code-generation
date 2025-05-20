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
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    char choice;
    char title[100];
    char content[500];

    do {
        printf("Enter title (or 'q' to quit): ");
        scanf("%s", title);

        if (strcmp(title, "q") == 0)
            break;

        printf("Enter content: ");
        scanf("%[^\n]s", content);

        strcpy(entries[num_entries].title, title);
        strcpy(entries[num_entries].content, content);
        num_entries++;

        printf("Entry saved.\n");

        printf("Add another entry? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    for (int i = 0; i < num_entries; i++) {
        printf("\nTitle: %s\nContent: %s\n", entries[i].title, entries[i].content);
    }

    for (int i = 0; i < num_entries; i++) {
        free(entries[i].title);
        free(entries[i].content);
    }

    return 0;
}
