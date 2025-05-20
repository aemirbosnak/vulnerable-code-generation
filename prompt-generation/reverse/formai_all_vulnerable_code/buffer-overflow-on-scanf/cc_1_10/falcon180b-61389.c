//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* newEntry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(diary[numEntries].date, 20, "%m/%d/%Y", tm);
    strncpy(diary[numEntries].entry, newEntry, MAX_ENTRY_LENGTH);
    numEntries++;
}

void readEntry(int index) {
    if (index < 0 || index >= numEntries) {
        printf("Invalid entry number.\n");
        return;
    }

    printf("Date: %s\n", diary[index].date);
    printf("Entry:\n%s\n", diary[index].entry);
}

void deleteEntry(int index) {
    if (index < 0 || index >= numEntries) {
        printf("Invalid entry number.\n");
        return;
    }

    numEntries--;
    for (int i = index; i < numEntries; i++) {
        strncpy(diary[i].date, diary[i+1].date, 20);
        strncpy(diary[i].entry, diary[i+1].entry, MAX_ENTRY_LENGTH);
    }
}

int main() {
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. Read entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char newEntry[MAX_ENTRY_LENGTH];
                printf("Enter your new entry: ");
                scanf(" %[^\n]", newEntry);
                addEntry(newEntry);
                break;
            }
            case 2: {
                int index;
                printf("Enter entry number: ");
                scanf("%d", &index);
                readEntry(index);
                break;
            }
            case 3: {
                int index;
                printf("Enter entry number: ");
                scanf("%d", &index);
                deleteEntry(index);
                break;
            }
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}