//FormAI DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
/*
 * C Digital Diary Program
 * Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100 // maximum number of diary entries

struct Entry {
    char date[11]; // format: DD/MM/YYYY
    char time[6]; // format: HH:MM
    char title[50];
    char content[1000];
};

struct Entry diary[MAX_ENTRIES]; // array of diary entries
int num_entries = 0; // current number of entries

void add_entry() {
    struct Entry e;
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", e.date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", e.time);
    printf("Enter the title: ");
    getchar(); // consume newline character
    fgets(e.title, 50, stdin);
    printf("Enter the content: ");
    fgets(e.content, 1000, stdin);
    diary[num_entries++] = e;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Title: %s", diary[i].title);
        printf("Content: %s", diary[i].content);
        printf("--------------------\n");
    }
}

void search_by_date() {
    char search_date[11];
    printf("Enter the date you want to search (DD/MM/YYYY): ");
    scanf("%s", search_date);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(search_date, diary[i].date) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Time: %s\n", diary[i].time);
            printf("Title: %s", diary[i].title);
            printf("Content: %s", diary[i].content);
            printf("--------------------\n");
        }
    }
}

void delete_entry() {
    int entry_index;
    printf("Enter the index of the entry you want to delete: ");
    scanf("%d", &entry_index);
    if (entry_index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = entry_index; i < num_entries - 1; i++) {
        diary[i] = diary[i+1];
    }
    num_entries--;
}

int main() {
    char choice;
    while (1) {
        printf("Select an option:\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search by date\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_entry();
                break;
            case '2':
                view_entries();
                break;
            case '3':
                search_by_date();
                break;
            case '4':
                delete_entry();
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}