//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    char dateBuf[20];
    time_t now = time(NULL);
    strftime(dateBuf, 20, "%Y-%m-%d", localtime(&now));

    printf("Enter your diary entry for %s:\n", dateBuf);
    fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(entries[numEntries].date, dateBuf);
    numEntries++;

    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntry() {
    char searchKey[MAX_ENTRY_LENGTH];
    printf("Enter search keyword: ");
    fgets(searchKey, MAX_ENTRY_LENGTH, stdin);
    searchKey[strcspn(searchKey, "\n")] = '\0'; // remove newline character

    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, searchKey)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            searchEntry();
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}