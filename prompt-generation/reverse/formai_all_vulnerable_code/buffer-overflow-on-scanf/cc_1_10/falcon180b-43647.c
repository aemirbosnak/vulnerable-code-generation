//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char title[50];
    char content[200];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter entry title: ");
    scanf("%s", entries[num_entries].title);
    printf("Enter entry content: ");
    scanf("%[^\n]", entries[num_entries].content);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].title, ctime(&entries[i].timestamp));
    }
}

void search_entries() {
    char search_term[50];
    printf("Enter search term: ");
    scanf("%s", search_term);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, search_term)) {
            printf("%s - %s\n", entries[i].title, ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}