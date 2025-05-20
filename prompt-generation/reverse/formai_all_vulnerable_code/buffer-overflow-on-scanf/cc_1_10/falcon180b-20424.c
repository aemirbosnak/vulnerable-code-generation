//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    printf("Enter title: ");
    scanf("%s", title);
    printf("Enter content: ");
    scanf("%s", content);

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(title, MAX_ENTRY_LENGTH, "%Y-%m-%d %H:%M:%S", tm);

    strncpy(entries[num_entries].title, title, MAX_ENTRY_LENGTH);
    strncpy(entries[num_entries].content, content, MAX_ENTRY_LENGTH);
    entries[num_entries].timestamp = now;
    num_entries++;
}

void view_entries() {
    printf("Number of entries: %d\n", num_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", entries[i].title, entries[i].content);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword: ");
    scanf("%s", keyword);

    int count = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword)!= NULL || strstr(entries[i].content, keyword)!= NULL) {
            printf("%s\n%s\n", entries[i].title, entries[i].content);
            count++;
        }
    }

    if (count == 0) {
        printf("No entries found.\n");
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}