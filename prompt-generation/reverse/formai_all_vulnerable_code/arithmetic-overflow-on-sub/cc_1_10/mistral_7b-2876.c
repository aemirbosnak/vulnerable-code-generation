//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define ENTRY_LENGTH 256

typedef struct {
    char title[ENTRY_LENGTH];
    char content[ENTRY_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\n-------- Digital Diary --------\n");
    printf("1. Write new entry\n");
    printf("2. Read entry\n");
    printf("3. Delete entry\n");
    printf("4. List entries\n");
    printf("5. Exit\n");
}

void write_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    printf("Enter title: ");
    fgets(entries[num_entries].title, ENTRY_LENGTH, stdin);
    entries[num_entries].title[strcspn(entries[num_entries].title, "\n")] = '\0';

    printf("Enter content: ");
    fgets(entries[num_entries].content, ENTRY_LENGTH, stdin);
    entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';

    time(&entries[num_entries].timestamp);
    num_entries++;

    printf("Entry saved successfully.\n");
}

void read_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    printf("\nTitle: %s\n", entries[index].title);
    printf("Content: %s\n", entries[index].content);
    printf("Timestamp: %s", ctime(&entries[index].timestamp));
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    for (int i = index; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    num_entries--;

    printf("Entry deleted successfully.\n");
}

void list_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\nList of Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("\nEntry %d:\n", i + 1);
        printf("Title: %s\n", entries[i].title);
        printf("Timestamp: %s", ctime(&entries[i].timestamp));
    }
}

int main() {
    int choice;
    int entry_index;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                write_entry();
                break;
            case 2:
                printf("Enter entry index: ");
                scanf("%d", &entry_index);
                read_entry(entry_index - 1);
                break;
            case 3:
                printf("Enter entry index: ");
                scanf("%d", &entry_index);
                delete_entry(entry_index - 1);
                break;
            case 4:
                list_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}