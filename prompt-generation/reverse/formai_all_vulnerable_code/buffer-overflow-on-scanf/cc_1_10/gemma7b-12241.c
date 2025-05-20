//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[20];
    char content[200];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
    Entry newEntry;

    printf("Enter the title of your entry: ");
    scanf("%s", newEntry.title);

    printf("Enter the content of your entry: ");
    scanf("%s", newEntry.content);

    newEntry.timestamp = time(NULL);

    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].timestamp == 0) {
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
        printf("Enter 1 to add an entry, 2 to display entries, or 3 to quit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                printf("Thank you for using your digital diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}