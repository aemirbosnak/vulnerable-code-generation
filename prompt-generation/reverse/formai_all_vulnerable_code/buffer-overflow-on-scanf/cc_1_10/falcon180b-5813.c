//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 5000

typedef struct {
    char title[100];
    time_t date;
    char text[ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* title, char* text) {
    time_t now = time(NULL);
    entries[num_entries].date = now;
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].text, text);
    num_entries++;
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Title: %s\nDate: %s\nText:\n%s\n\n", entries[i].title, ctime(&entries[i].date), entries[i].text);
    }
}

void search_entries(char* keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].text, keyword)) {
            printf("Title: %s\nDate: %s\nText:\n%s\n\n", entries[i].title, ctime(&entries[i].date), entries[i].text);
        }
    }
}

int main() {
    char title[100];
    char text[ENTRY_LENGTH];

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        scanf("%d", &num_entries);

        switch (num_entries) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter text: ");
                scanf("%s", text);
                add_entry(title, text);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter keyword: ");
                scanf("%s", title);
                search_entries(title);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}