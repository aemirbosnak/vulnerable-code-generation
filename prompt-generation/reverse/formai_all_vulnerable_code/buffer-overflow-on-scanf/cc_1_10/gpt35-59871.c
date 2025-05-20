//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char title[100];
    char date[20];
    char content[1000];
};

int num_entries = 0;
struct DiaryEntry entries[MAX_ENTRIES];

void print_menu() {
    printf("\n\n********** Digital Diary **********\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("\nSorry, the diary is full!");
        return;
    }

    struct DiaryEntry entry;

    printf("\nEnter Title: ");
    scanf("%s", entry.title);

    printf("\nEnter Date (dd/mm/yyyy): ");
    scanf("%s", entry.date);

    printf("\nEnter Content: ");
    scanf(" %[^\n]s", entry.content);

    entries[num_entries++] = entry;
}

void view_entries() {
    if (num_entries == 0) {
        printf("\nNo entries found!");
        return;
    }

    printf("\n\n***************** All Entries (%d) *****************\n", num_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("\n********** Entry %d **********\n", i + 1);
        printf("Title: %s\n", entries[i].title);
        printf("Date: %s\n", entries[i].date);
        printf("Content: %s\n\n", entries[i].content);
    }
}

void search_entry() {
    if (num_entries == 0) {
        printf("\nSorry, no entries found!");
        return;
    }

    char query[100];
    int results[MAX_ENTRIES];
    int num_results = 0;

    printf("\nEnter search query: ");
    scanf("%s", query);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, query) || strstr(entries[i].content, query)) {
            results[num_results++] = i;
        }
    }

    if (num_results == 0) {
        printf("\nSorry, no results found!");
        return;
    }

    printf("\n\n***************** Search Results (%d) *****************\n", num_results);
    for (int i = 0; i < num_results; i++) {
        printf("\n********** Result %d **********\n", i + 1);
        printf("Title: %s\n", entries[results[i]].title);
        printf("Date: %s\n", entries[results[i]].date);
        printf("Content: %s\n\n", entries[results[i]].content);
    }
}

int main() {
    int option;

    do {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
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
                printf("\n\nThank you for using Digital Diary!\n\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    } while (option != 4);

    return 0;
}