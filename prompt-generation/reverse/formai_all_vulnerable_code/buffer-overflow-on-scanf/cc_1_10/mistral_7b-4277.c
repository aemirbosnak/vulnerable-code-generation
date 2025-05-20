//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 200

typedef struct {
    char title[50];
    char content[ENTRY_LENGTH];
    int entry_number;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;
int current_entry = 0;

void print_menu() {
    printf("-------------------------------\n");
    printf("| Digital Diary | Menu |\n");
    printf("-------------------------------\n");
    printf("| 1. Add Entry |\n");
    printf("| 2. View Entry |\n");
    printf("| 3. Delete Entry |\n");
    printf("| 4. Exit       |\n");
    printf("-------------------------------\n");
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    printf("Enter title for new entry: ");
    scanf("%s", entries[num_entries].title);

    printf("Enter content for new entry: ");
    scanf("%[^\n]s", entries[num_entries].content);

    entries[num_entries].entry_number = num_entries + 1;
    num_entries++;

    printf("New entry added successfully.\n");
}

void view_entry() {
    if (num_entries == 0) {
        printf("No entries to view.\n");
        return;
    }

    if (current_entry < 0 || current_entry >= num_entries) {
        printf("Invalid entry number.\n");
        return;
    }

    printf("\nEntry %d:\n", current_entry + 1);
    printf("Title: %s\n", entries[current_entry].title);
    printf("Content: %s\n", entries[current_entry].content);
}

void delete_entry() {
    if (num_entries == 0) {
        printf("No entries to delete.\n");
        return;
    }

    if (current_entry < 0 || current_entry >= num_entries) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = current_entry; i < num_entries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    num_entries--;

    printf("Entry %d deleted successfully.\n", current_entry + 1);
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
                view_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting Digital Diary...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}