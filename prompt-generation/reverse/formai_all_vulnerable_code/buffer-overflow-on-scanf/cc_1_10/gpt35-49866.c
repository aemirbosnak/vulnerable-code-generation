//FormAI DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

struct entry {
    char date[11];
    char content[1000];
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Add entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (num_entries < MAX_ENTRIES) {
        printf("Enter today's date (MM/DD/YYYY): ");
        scanf("%s", entries[num_entries].date);
        printf("Enter your diary entry (up to 1000 characters):\n");
        scanf("%s", entries[num_entries].content);
        num_entries++;
    } else {
        printf("Sorry, the diary is full.\n");
    }
}

void view_entries() {
    if (num_entries == 0) {
        printf("There are no entries in the diary.\n");
    } else {
        printf("Diary entries:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s: %s\n", entries[i].date, entries[i].content);
        }
    }
}

void search_entry() {
    printf("Enter a search term: ");
    char search_term[1000];
    scanf("%s", search_term);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, search_term) != NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].content);
            found = 1;
        }
    }
    if (!found) {
        printf("No matches found.\n");
    }
}

int main() {
    int choice;
    do {
        print_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}