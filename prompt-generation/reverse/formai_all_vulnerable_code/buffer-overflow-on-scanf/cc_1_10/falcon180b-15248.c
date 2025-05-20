//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

int entryCount = 0;
Entry entries[MAX_ENTRIES];

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", entries[entryCount].title);

    printf("Enter content: ");
    fgets(entries[entryCount].content, MAX_ENTRY_LENGTH, stdin);
    entries[entryCount].content[strcspn(entries[entryCount].content, "\n")] = '\0';

    time(&entries[entryCount].timestamp);
    entryCount++;

    printf("Entry added.\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Showing %d entries:\n", entryCount);
    for (int i = 0; i < entryCount; i++) {
        printf("%s - %s\n", entries[i].title, entries[i].content);
    }
}

void searchEntries() {
    char searchTerm[MAX_ENTRY_LENGTH];

    printf("Enter search term: ");
    scanf("%s", searchTerm);

    for (int i = 0; i < entryCount; i++) {
        if (strstr(entries[i].title, searchTerm) || strstr(entries[i].content, searchTerm)) {
            printf("%s - %s\n", entries[i].title, entries[i].content);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Diary 3000!\n");
    printf("Press 1 to add an entry.\n");
    printf("Press 2 to view entries.\n");
    printf("Press 3 to search entries.\n");
    printf("Press 0 to exit.\n");

    int choice;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}