//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char name[50];
    char content[200];
    int timestamp;
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
    Entry newEntry;

    printf("Enter name: ");
    scanf("%s", newEntry.name);

    printf("Enter content: ");
    scanf("%[^\n]%*c", newEntry.content);

    newEntry.timestamp = time(NULL);

    entries[entries[MAX_ENTRIES - 1].timestamp] = newEntry;
}

void displayEntries() {
    int i = 0;

    printf("Entries:\n");
    for (i = 0; entries[i].timestamp != -1; i++) {
        printf("Name: %s\n", entries[i].name);
        printf("Content: %s\n", entries[i].content);
        printf("Timestamp: %d\n", entries[i].timestamp);
        printf("\n");
    }
}

int main() {
    int option;

    entries[MAX_ENTRIES - 1].timestamp = -1;

    while (1) {
        printf("Enter 1 to add an entry, 2 to display entries, or 3 to exit: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}