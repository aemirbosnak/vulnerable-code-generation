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
    int count = 0;
    int choice;

    while (count < MAX_ENTRIES) {
        printf("Enter entry %d:\n", count + 1);
        printf("Title: ");
        fgets(entries[count].title, sizeof(entries[count].title), stdin);
        printf("Content: ");
        fgets(entries[count].content, sizeof(entries[count].content), stdin);
        count++;
        printf("Do you want to add another entry? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        if (choice == 0) break;
    }

    printf("\nDisplaying all entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s", entries[i].title);
        printf("Content: %s", entries[i].content);
    }

    return 0;
}
