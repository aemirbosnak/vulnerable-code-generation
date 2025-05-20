//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct Entry {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
};

void addEntry(struct Entry* entries, int numEntries, char* newText) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    strcpy(entries[numEntries].text, newText);
    time(&entries[numEntries].timestamp);
    numEntries++;
}

void displayEntries(struct Entry* entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", entries[i].text, ctime(&entries[i].timestamp));
    }
}

int main() {
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    printf("Welcome to the Digital Diary!\n\n");

    while (1) {
        printf("1. Add Entry\n2. Display Entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char newText[MAX_ENTRY_LENGTH];
                printf("Enter your new entry:\n");
                scanf("%s", newText);
                addEntry(entries, numEntries, newText);
                break;
            }
            case 2: {
                displayEntries(entries, numEntries);
                break;
            }
            case 3: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}