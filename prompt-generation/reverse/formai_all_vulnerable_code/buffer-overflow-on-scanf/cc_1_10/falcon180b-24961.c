//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

// Struct to hold a diary entry
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry diary[], int numEntries) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[numEntries].date, 20, "%Y-%m-%d", t);

    printf("Write your entry for %s:\n", diary[numEntries].date);
    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
}

void viewEntries(DiaryEntry diary[], int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n%s\n\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;

    while (numEntries < MAX_ENTRIES) {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, numEntries);
                numEntries++;
                break;
            case 2:
                viewEntries(diary, numEntries);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}