#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_ENTRIES 10

typedef struct {
    char title[50];
    char content[200];
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    printf("Enter up to %d diary entries:\n", MAX_ENTRIES);
    while (numEntries < MAX_ENTRIES) {
        printf("Title: ");
        fgets(entries[numEntries].title, sizeof(entries[numEntries].title), stdin);
        entries[numEntries].title[strcspn(entries[numEntries].title, "\n")] = '\0';

        printf("Content: ");
        fgets(entries[numEntries].content, sizeof(entries[numEntries].content), stdin);
        entries[numEntries].content[strcspn(entries[numEntries].content, "\n")] = '\0';

        numEntries++;
        if (numEntries == MAX_ENTRIES) break;
        printf("Do you want to add another entry? (y/n): ");
        getchar(); // Consume newline character left by previous fgets
        char response;
        scanf("%c", &response);
        if (response != 'y' && response != 'Y') break;
    }

    printf("\nDisplaying all entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Title: %s\nContent: %s\n\n", entries[i].title, entries[i].content);
    }

    return 0;
}
