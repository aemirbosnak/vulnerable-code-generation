//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[50];
    char content[200];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
    Entry newEntry;

    printf("Enter the title of your entry:");
    scanf("%s", newEntry.title);

    printf("Enter the content of your entry:");
    scanf("%s", newEntry.content);

    newEntry.timestamp = time(NULL);

    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].timestamp == NULL) {
            entries[i] = newEntry;
            break;
        }
    }
}

void displayEntries() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].timestamp) {
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Timestamp: %s\n", asctime(localtime(&entries[i].timestamp)));
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add an entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}