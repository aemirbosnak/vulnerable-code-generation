//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 500

typedef struct {
    time_t timestamp;
    char entry[ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }

    time_t now = time(NULL);
    printf("What do you want to write?\n");
    scanf("%s", entries[entryCount].entry);
    entries[entryCount].timestamp = now;
    entryCount++;
}

void viewEntries() {
    for (int i = 0; i < entryCount; i++) {
        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].entry);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Digital Diary.\n");
    printf("In this post-apocalyptic world, your thoughts are your only companion.\n");

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");

        int choice = rand() % 3;
        switch (choice) {
            case 0:
                addEntry();
                break;
            case 1:
                viewEntries();
                break;
            case 2:
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}