#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_TITLE_LENGTH 256
#define MAX_CONTENT_LENGTH 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

int main() {
    DiaryEntry *entries = (DiaryEntry *)malloc(MAX_ENTRIES * sizeof(DiaryEntry));
    if (entries == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int num_entries = 0;
    while (num_entries < MAX_ENTRIES) {
        printf("Enter title: ");
        fgets(entries[num_entries].title, MAX_TITLE_LENGTH, stdin);
        entries[num_entries].title[strcspn(entries[num_entries].title, "\n")] = '\0';

        printf("Enter content: ");
        fgets(entries[num_entries].content, MAX_CONTENT_LENGTH, stdin);
        entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';

        num_entries++;

        printf("Do you want to add another entry? (y/n): ");
        char response;
        scanf(" %c", &response);
        getchar(); // Consume newline character left by scanf
        if (response != 'y' && response != 'Y') {
            break;
        }
    }

    printf("\nDisplaying all entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Title: %s\nContent: %s\n\n", entries[i].title, entries[i].content);
    }

    free(entries);

    return 0;
}
