//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 500

struct entry {
    char title[ENTRY_LENGTH];
    char content[ENTRY_LENGTH];
    time_t timestamp;
};

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Maximum entries limit reached.\n");
                } else {
                    printf("Title: ");
                    scanf("%s", entries[num_entries].title);
                    printf("Content: ");
                    scanf("%s", entries[num_entries].content);
                    entries[num_entries].timestamp = time(NULL);
                    num_entries++;
                    printf("Entry added successfully.\n");
                }
                break;
            case '2':
                printf("Title\tContent\tTimestamp\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s\t%s\t%s", entries[i].title, entries[i].content, ctime(&entries[i].timestamp));
                }
                break;
            case '3':
                printf("Search by title: ");
                scanf("%s", entries[num_entries].title);
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].title, entries[num_entries].title) == 0) {
                        printf("Title: %s\nContent: %s\nTimestamp: %s", entries[i].title, entries[i].content, ctime(&entries[i].timestamp));
                    }
                }
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}