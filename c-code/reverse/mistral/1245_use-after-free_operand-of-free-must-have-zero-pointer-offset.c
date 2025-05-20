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
    time_t timestamp;
} DiaryEntry;

int main() {
    DiaryEntry *entries = malloc(MAX_ENTRIES * sizeof(DiaryEntry));
    int num_entries = 0;

    char title[100];
    char content[500];

    while (num_entries < MAX_ENTRIES) {
        printf("Enter title: ");
        scanf("%s", title);
        printf("Enter content: ");
        scanf("%s", content);

        entries[num_entries].timestamp = time(NULL);
        strcpy(entries[num_entries].title, title);
        strcpy(entries[num_entries].content, content);

        num_entries++;
    }

    printf("\nDiary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. Title: %s\n", i + 1, entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
    }

    free(entries);

    return 0;
}
