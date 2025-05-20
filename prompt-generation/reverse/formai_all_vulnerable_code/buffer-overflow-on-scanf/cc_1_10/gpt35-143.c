//FormAI DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 50
#define MAX_TITLE_LENGTH 50
#define MAX_BODY_LENGTH 250

struct diary_entry {
    char entry_title[MAX_TITLE_LENGTH];
    char entry_body[MAX_BODY_LENGTH];
    time_t entry_time;
};

struct diary {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries;
};

void display_menu() {
    printf("Digital Diary v1.0\n");
    printf("------------------\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
}

void add_entry(struct diary *d) {
    char title[MAX_TITLE_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Enter title of entry: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);

    printf("Enter body of entry: ");
    fgets(body, MAX_BODY_LENGTH, stdin);

    struct diary_entry entry;
    strcpy(entry.entry_title, title);
    strcpy(entry.entry_body, body);
    entry.entry_time = time(NULL);

    d->entries[d->num_entries] = entry;
    d->num_entries++;
}

void view_all_entries(struct diary *d) {
    int i;
    for (i = 0; i < d->num_entries; i++) {
        printf("------------------\n");
        printf("Title: %s\n", d->entries[i].entry_title);
        printf("Time: %s", asctime(localtime(&d->entries[i].entry_time)));
        printf("Body:\n%s\n", d->entries[i].entry_body);
    }
    printf("------------------\n");
}

void search_entries(struct diary *d) {
    char search_term[MAX_TITLE_LENGTH];
    int i;
    int found = 0;

    printf("Enter search term: ");
    fgets(search_term, MAX_TITLE_LENGTH, stdin);

    for (i = 0; i < d->num_entries; i++) {
        if (strstr(d->entries[i].entry_title, search_term)) {
            printf("------------------\n");
            printf("Title: %s\n", d->entries[i].entry_title);
            printf("Time: %s", asctime(localtime(&d->entries[i].entry_time)));
            printf("Body:\n%s\n", d->entries[i].entry_body);
            found = 1;
        }
    }
    if (!found) {
        printf("No matching entries found.\n");
    }
}

int main() {
    struct diary d;
    d.num_entries = 0;

    int menu_choice = 0;
    do {
        display_menu();

        printf("Enter choice: ");
        scanf("%d", &menu_choice);
        getchar(); // absorb new line character

        switch (menu_choice) {
            case 1:
                add_entry(&d);
                break;
            case 2:
                view_all_entries(&d);
                break;
            case 3:
                search_entries(&d);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (menu_choice != 4);

    return 0;
}