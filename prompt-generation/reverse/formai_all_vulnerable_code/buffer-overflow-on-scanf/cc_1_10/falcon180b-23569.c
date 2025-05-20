//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[500];
} DiaryEntry;

void addEntry(DiaryEntry entries[], int numEntries) {
    char date[20];
    char entry[500];
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", date);
    printf("Enter entry: ");
    fgets(entry, sizeof(entry), stdin);
    entry[strcspn(entry, "\n")] = '\0';
    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);
    numEntries++;
}

void viewEntries(DiaryEntry entries[], int numEntries) {
    printf("Date\t\tEntry\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t\t%s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntries(DiaryEntry entries[], int numEntries, char searchTerm[]) {
    printf("Search results:\n");
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, searchTerm)!= NULL) {
            printf("%s\t\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            addEntry(entries, numEntries);
            break;
        case '2':
            viewEntries(entries, numEntries);
            break;
        case '3':
            printf("Enter search term: ");
            char searchTerm[100];
            scanf("%s", searchTerm);
            searchEntries(entries, numEntries, searchTerm);
            break;
        case '4':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}