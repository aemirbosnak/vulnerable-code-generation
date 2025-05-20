//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char title[100];
    char content[1000];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf(" diary is full\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", entries[num_entries].title);

    printf("Enter content: ");
    fgets(entries[num_entries].content, 1000, stdin);

    time(&entries[num_entries].timestamp);
    num_entries++;

    printf("Entry added\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf(" diary is empty\n");
        return;
    }

    printf("Title\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].title, ctime(&entries[i].timestamp));
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf(" diary is empty\n");
        return;
    }

    char keyword[100];
    printf("Enter keyword: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, keyword)) {
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    srand(time(0));

    int choice;
    do {
        printf(" diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}