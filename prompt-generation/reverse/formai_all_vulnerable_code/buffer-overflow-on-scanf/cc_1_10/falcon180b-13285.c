//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} DiaryEntry;

int numEntries = 0;
DiaryEntry entries[MAX_ENTRIES];

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter your entry:\n");
    fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    entries[numEntries].timestamp = time(NULL);
    numEntries++;

    printf("Entry added.\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Viewing entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", entries[i].entry);
        printf("Timestamp: %s\n\n", ctime(&entries[i].timestamp));
    }
}

void searchEntries(char *keyword) {
    if (numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Searching for '%s'...\n", keyword);
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s\n", entries[i].entry);
            printf("Timestamp: %s\n\n", ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n\n");

    int choice;
    do {
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            printf("Enter keyword to search: ");
            char keyword[MAX_ENTRY_LENGTH];
            fgets(keyword, MAX_ENTRY_LENGTH, stdin);
            searchEntries(keyword);
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}