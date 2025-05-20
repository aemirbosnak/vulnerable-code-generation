//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

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
    printf("Enter entry title: ");
    scanf("%s", title);
    printf("Enter entry content: ");
    scanf("%s", content);
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].content, content);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;
}

void view_entries() {
    printf("Viewing all entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s\n%s\n", i+1, entries[i].title, entries[i].content);
        printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].content, keyword)) {
            printf("%d. %s\n%s\n", i+1, entries[i].title, entries[i].content);
            printf("Timestamp: %s\n", ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    while (1) {
        printf("Digital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}