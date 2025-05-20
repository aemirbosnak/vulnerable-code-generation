//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char title[ENTRY_LENGTH];
    char content[ENTRY_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int current_entry = 0;

void save_entry() {
    entries[current_entry].timestamp = time(NULL);
    printf("Entry saved!\n");
    current_entry++;
}

void load_entry(int index) {
    if (index >= 0 && index < MAX_ENTRIES && entries[index].title[0] != '\0') {
        printf("\nTitle: %s\n", entries[index].title);
        printf("Content:\n%s\n", entries[index].content);
        printf("Timestamp: %s", ctime(&entries[index].timestamp));
    } else {
        printf("Invalid entry index.\n");
    }
}

void new_entry() {
    if (current_entry < MAX_ENTRIES) {
        printf("Enter title: ");
        fgets(entries[current_entry].title, ENTRY_LENGTH, stdin);
        entries[current_entry].title[strcspn(entries[current_entry].title, "\n")] = '\0';

        printf("Enter content: ");
        fgets(entries[current_entry].content, ENTRY_LENGTH, stdin);
        entries[current_entry].content[strcspn(entries[current_entry].content, "\n")] = '\0';

        save_entry();
    } else {
        printf("Maximum number of entries reached.\n");
    }
}

void list_entries() {
    int i;

    for (i = 0; i < current_entry; i++) {
        printf("\n[%d] Title: %s", i, entries[i].title);
    }
}

int main() {
    int choice;
    char search_title[ENTRY_LENGTH];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. New Entry\n");
        printf("2. Load Entry\n");
        printf("3. List Entries\n");
        printf("4. Search by Title\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                new_entry();
                break;
            case 2:
                printf("Enter entry index: ");
                scanf("%d", &choice);
                load_entry(choice);
                break;
            case 3:
                list_entries();
                break;
            case 4:
                printf("Enter title to search: ");
                scanf("%s", search_title);
                for (int i = 0; i < current_entry; i++) {
                    if (strstr(entries[i].title, search_title) != NULL) {
                        load_entry(i);
                        break;
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}