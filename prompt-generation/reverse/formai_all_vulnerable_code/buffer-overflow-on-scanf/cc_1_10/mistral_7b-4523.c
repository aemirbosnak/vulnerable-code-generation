//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\n*** DigiDiary Menu ***\n");
    printf("1. Add new entry\n");
    printf("2. View all entries\n");
    printf("3. View last entry\n");
    printf("4. Search entries\n");
    printf("5. Delete entry\n");
    printf("6. Quit\n");
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    Entry *entry = &entries[num_entries];

    printf("Enter title: ");
    fgets(entry->title, ENTRY_SIZE, stdin);
    entry->title[strcspn(entry->title, "\n")] = '\0';

    printf("Enter content: ");
    fgets(entry->content, ENTRY_SIZE, stdin);
    entry->content[strcspn(entry->content, "\n")] = '\0';

    entry->timestamp = time(NULL);
    num_entries++;

    printf("Entry added successfully.\n");
}

void view_all_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n--- Current Entries ---\n");

    for (int i = 0; i < num_entries; i++) {
        Entry *entry = &entries[i];
        printf("\nTitle: %s\n", entry->title);
        printf("Content: %s\n", entry->content);
        printf("Timestamp: %s\n", ctime(&entry->timestamp));
    }
}

void view_last_entry() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    Entry *entry = &entries[num_entries - 1];
    printf("\nLast Entry:\n");
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

void search_entries() {
    char search_term[ENTRY_SIZE];
    printf("Enter search term: ");
    fgets(search_term, ENTRY_SIZE, stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    int found = 0;

    for (int i = 0; i < num_entries; i++) {
        Entry *entry = &entries[i];
        if (strstr(entry->title, search_term) || strstr(entry->content, search_term)) {
            printf("\nEntry Found:\n");
            printf("Title: %s\n", entry->title);
            printf("Content: %s\n", entry->content);
            printf("Timestamp: %s\n", ctime(&entry->timestamp));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No entries found with the given search term.\n");
    }
}

void delete_entry() {
    int index;
    printf("Enter index of the entry to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    memmove(&entries[index], &entries[index + 1], (num_entries - index - 1) * sizeof(Entry));
    num_entries--;

    printf("Entry deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_all_entries();
                break;
            case 3:
                view_last_entry();
                break;
            case 4:
                search_entries();
                break;
            case 5:
                delete_entry();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}