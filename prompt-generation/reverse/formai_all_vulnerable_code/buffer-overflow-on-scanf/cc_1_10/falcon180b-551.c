//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char title[100];
    char content[1000];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* title, char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].content, content);
    time(&entries[num_entries].timestamp);
    num_entries++;
    printf("Entry added successfully.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Title\tContent\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\n", entries[i].title, entries[i].content, ctime(&entries[i].timestamp));
    }
}

void search_entries(char* keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Search results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].content, keyword)) {
            printf("%s\t%s\t%s\n", entries[i].title, entries[i].content, ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    char title[100], content[1000];
    while (1) {
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%s", content);
                add_entry(title, content);
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
                printf("Invalid choice.\n");
        }
    }
    return 0;
}