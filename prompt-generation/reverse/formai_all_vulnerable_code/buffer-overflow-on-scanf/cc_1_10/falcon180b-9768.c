//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry* entries, int count, char* date, char* content) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[count].date, date);
    strcpy(entries[count].content, content);

    count++;
}

void display_entries(struct entry* entries, int count) {
    printf("Entries:\n");

    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].content);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char date[20];
                char content[MAX_ENTRY_LENGTH];

                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);

                printf("Enter content:\n");
                scanf("%[^\n]", content);

                add_entry(entries, count, date, content);
                break;
            }

        case 2:
            display_entries(entries, count);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}