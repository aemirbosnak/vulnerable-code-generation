#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct {
    char date[20];
    char content[100];
} DiaryEntry;

int main() {
    DiaryEntry *entries = (DiaryEntry *)malloc(MAX_ENTRIES * sizeof(DiaryEntry));
    if (!entries) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int count = 0;
    while (count < MAX_ENTRIES) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", entries[count].date);
        getchar(); // Consume newline character left by scanf
        printf("Enter entry: ");
        fgets(entries[count].content, sizeof(entries[count].content), stdin);
        entries[count].content[strcspn(entries[count].content, "\n")] = '\0'; // Remove newline character
        count++;
        printf("Add another entry? (y/n): ");
        char choice;
        scanf("%c", &choice);
        getchar(); // Consume newline character left by scanf
        if (choice != 'y' && choice != 'Y') break;
    }

    for (int i = 0; i < count; i++) {
        printf("\nDate: %s\nContent: %s\n", entries[i].date, entries[i].content);
    }

    free(entries);

    return 0;
}
