//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 200

struct Entry {
    char title[100];
    char content[ENTRY_LENGTH];
    time_t timestamp;
};

struct Entry diary[MAX_ENTRIES];
int current_entry = -1;

void print_menu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add entry\n");
    printf("2. View entry\n");
    printf("3. Delete entry\n");
    printf("4. View all entries\n");
    printf("5. Quit\n");
}

int get_next_empty_entry() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].title[0] == '\0') {
            return i;
        }
    }
    return -1;
}

void add_entry() {
    if (current_entry == MAX_ENTRIES - 1) {
        printf("Diary is full. Please delete an entry to add a new one.\n");
        return;
    }

    int empty_entry = get_next_empty_entry();
    if (empty_entry == -1) {
        printf("Diary is full. Please delete an entry to add a new one.\n");
        return;
    }

    current_entry = empty_entry;

    printf("Enter entry title: ");
    scanf("%s", diary[current_entry].title);

    printf("Enter entry content: ");
    fgets(diary[current_entry].content, ENTRY_LENGTH, stdin);

    diary[current_entry].timestamp = time(NULL);

    printf("Entry added successfully.\n");
}

void view_entry() {
    if (current_entry == -1) {
        printf("No current entry.\n");
        return;
    }

    printf("Title: %s\n", diary[current_entry].title);
    printf("Content: %s", diary[current_entry].content);
}

void delete_entry() {
    if (current_entry == -1) {
        printf("No current entry.\n");
        return;
    }

    diary[current_entry].title[0] = '\0';
    current_entry = -1;

    printf("Entry deleted successfully.\n");
}

void view_all_entries() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].title[0] != '\0') {
            printf("Title: %s\n", diary[i].title);
            printf("Content: %s", diary[i].content);
            printf("\n");
        }
    }
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
                if (current_entry != -1) {
                    view_entry();
                } else {
                    printf("No current entry.\n");
                }
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                view_all_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}