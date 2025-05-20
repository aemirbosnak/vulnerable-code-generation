//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Sorry, you can only have %d entries.\n", MAX_ENTRIES);
        return;
    }

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(entries[numEntries].date, 20, "%Y-%m-%d %H:%M:%S", tm);

    printf("Enter your diary entry:\n");
    fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);

    numEntries++;
    printf("Entry added.\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("Diary entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void deleteEntry() {
    if (numEntries == 0) {
        printf("No entries yet.\n");
        return;
    }

    int choice;
    printf("Enter the number of the entry you want to delete:\n");
    scanf("%d", &choice);

    if (choice >= 0 && choice < numEntries) {
        numEntries--;
        for (int i = choice; i < numEntries; i++) {
            strcpy(entries[i].date, entries[i+1].date);
            strcpy(entries[i].entry, entries[i+1].entry);
        }
        printf("Entry deleted.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    srand(time(NULL));

    int choice;
    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
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