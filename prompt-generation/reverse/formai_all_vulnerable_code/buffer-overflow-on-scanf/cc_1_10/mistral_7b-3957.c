//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char description[50];
} Entry;

Entry diary[MAX_ENTRIES];
int current_entry = 0;

void print_menu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Quit\n");
}

void add_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Diary is full. Please delete an entry first.\n");
        return;
    }

    printf("Enter title for the entry: ");
    scanf("%s", diary[current_entry].title);

    printf("Enter description for the entry: ");
    scanf("%s", diary[current_entry].description);

    current_entry++;
}

void view_entry() {
    if (current_entry == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\nEntry:\n");
    printf("Title: %s\n", diary[current_entry - 1].title);
    printf("Description: %s\n", diary[current_entry - 1].description);
}

void delete_entry() {
    if (current_entry == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    current_entry--;
    memset(&diary[current_entry], 0, sizeof(Entry));
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}