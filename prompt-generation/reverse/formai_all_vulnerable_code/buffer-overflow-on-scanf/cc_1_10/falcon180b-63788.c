//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int numEntries = 0;
DiaryEntry diary[MAX_ENTRIES];

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[numEntries].date);

    printf("Enter your entry:\n");
    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);

    numEntries++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntry() {
    char keyword[MAX_ENTRY_LENGTH];

    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    srand(time(0));

    int choice;
    do {
        printf("Digital Diary Menu:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
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
                searchEntry();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}