//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Sorry, diary is full!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[numEntries].date, 20, "%Y-%m-%d %H:%M:%S", t);

    printf("Enter your entry:\n");
    fgets(entries[numEntries].entry, MAX_LENGTH, stdin);
    entries[numEntries].entry[strcspn(entries[numEntries].entry, "\n")] = '\0';

    numEntries++;
}

void viewEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\nPress ENTER to continue...\n");
        getchar();
    } while (choice!= 3);

    return 0;
}