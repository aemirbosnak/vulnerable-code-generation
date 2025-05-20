//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int numEntries = 0;
DiaryEntry diary[MAX_ENTRIES];

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    DiaryEntry newEntry;
    time_t now = time(NULL);
    strftime(newEntry.date, 20, "%Y-%m-%d", localtime(&now));

    printf("Enter your diary entry:\n");
    fgets(newEntry.entry, MAX_ENTRY_LENGTH, stdin);

    diary[numEntries] = newEntry;
    numEntries++;

    printf("Entry added.\n");
}

void viewEntry() {
    if (numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("View which entry? (0-%d)\n", numEntries - 1);
    int index;
    scanf("%d", &index);

    if (index >= numEntries || index < 0) {
        printf("Invalid index.\n");
        return;
    }

    printf("Date: %s\n", diary[index].date);
    printf("Entry: %s\n", diary[index].entry);
}

void deleteEntry() {
    if (numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Delete which entry? (0-%d)\n", numEntries - 1);
    int index;
    scanf("%d", &index);

    if (index >= numEntries || index < 0) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < numEntries - 1; i++) {
        diary[i] = diary[i + 1];
    }
    numEntries--;

    printf("Entry deleted.\n");
}

int main() {
    srand(time(NULL));

    while (1) {
        printf("1. Add entry\n2. View entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}