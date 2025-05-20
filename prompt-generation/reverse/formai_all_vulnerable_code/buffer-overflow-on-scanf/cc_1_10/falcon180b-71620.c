//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
};

typedef struct entry Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char date[20];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    char content[MAX_ENTRY_LENGTH];
    printf("Enter content: ");
    fgets(content, MAX_ENTRY_LENGTH, stdin);
    content[strcspn(content, "\n")] = '\0'; // Remove newline character

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].content, content);
    num_entries++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].content);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword to search: ");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, keyword)) {
            printf("%s - %s\n", entries[i].date, entries[i].content);
        }
    }
}

int main() {
    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}