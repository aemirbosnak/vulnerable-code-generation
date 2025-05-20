//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Entry {
    char date[11];
    char title[21];
    char text[101];
};

struct Entry diary[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("Digital Diary Menu:\n");
    printf("1. Add new entry\n");
    printf("2. View all entries\n");
    printf("3. Search entry by date\n");
    printf("4. Search entry by title\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter date (mm/dd/yy): ");
    scanf("%s", diary[num_entries].date);
    printf("Enter title: ");
    scanf("%s", diary[num_entries].title);
    printf("Enter text: ");
    scanf("%s", diary[num_entries].text);
    num_entries++;
}

void view_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].title);
    }
}

void search_by_date() {
    char date[11];
    printf("Enter date to search (mm/dd/yy): ");
    scanf("%s", date);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("%s - %s\n", diary[i].date, diary[i].title);
            break;
        }
    }
}

void search_by_title() {
    char title[21];
    printf("Enter title to search: ");
    scanf("%s", title);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].title, title) == 0) {
            printf("%s - %s\n", diary[i].date, diary[i].title);
            break;
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
                view_all_entries();
                break;
            case 3:
                search_by_date();
                break;
            case 4:
                search_by_title();
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}