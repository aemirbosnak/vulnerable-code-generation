#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_LENGTH 256

typedef struct {
    char title[MAX_LENGTH];
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry* entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Cannot add more entries.\n");
        return;
    }
    entries[entry_count] = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    if (!entries[entry_count]) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter title: ");
    fgets(entries[entry_count]->title, MAX_LENGTH, stdin);
    entries[entry_count]->title[strcspn(entries[entry_count]->title, "\n")] = '\0';
    printf("Enter content: ");
    fgets(entries[entry_count]->content, MAX_LENGTH, stdin);
    entries[entry_count]->content[strcspn(entries[entry_count]->content, "\n")] = '\0';
    entry_count++;
}

void display_entries() {
    for (int i = 0; i < entry_count; i++) {
        printf("Title: %s\n", entries[i]->title);
        printf("Content: %s\n", entries[i]->content);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                for (int i = 0; i < entry_count; i++) {
                    free(entries[i]);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
