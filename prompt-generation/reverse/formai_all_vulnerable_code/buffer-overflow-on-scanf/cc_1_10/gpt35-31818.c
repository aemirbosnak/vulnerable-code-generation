//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DiaryEntry {
    char date[20];
    char entry[1000];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int* numEntries) {
    char date[20];
    char entry[1000];

    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", date);
    getchar(); // remove enter from input buffer

    printf("Enter diary entry:\n");
    fgets(entry, 1000, stdin);
    strtok(entry, "\n"); // remove newline character from entry

    strcpy(diary[*numEntries].date, date);
    strcpy(diary[*numEntries].entry, entry);
    (*numEntries)++;

    printf("Entry added successfully!\n");
}

void viewEntries(DiaryEntry* diary, int numEntries) {
    if (numEntries == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("Date\t\tEntry\n");
    printf("-------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[1000];
    int numEntries = 0;
    int choice = 0;

    while (choice != 3) {
        printf("\nChoose an option:\n");
        printf("1. Add diary entry\n");
        printf("2. View all diary entries\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                viewEntries(diary, numEntries);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}