//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char content[ENTRY_SIZE];
    int index;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void list_entries() {
    if (num_entries == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\nDiary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s\n", i + 1, entries[i].title);
    }
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    printf("\nEnter title for new entry: ");
    scanf("%s", entries[num_entries].title);
    printf("Enter content for new entry: ");
    scanf("%[^\n]s", entries[num_entries].content);

    entries[num_entries].index = num_entries;
    num_entries++;
}

void delete_entry() {
    if (num_entries == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\nEnter index of the entry to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 1 || index > num_entries) {
        printf("Invalid index. Cannot delete entry.\n");
        return;
    }

    for (int i = index - 1; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    num_entries--;
}

int main() {
    char command[20];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. List Entries\n");
        printf("2. Add Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                list_entries();
                break;
            case '2':
                add_entry();
                break;
            case '3':
                delete_entry();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}