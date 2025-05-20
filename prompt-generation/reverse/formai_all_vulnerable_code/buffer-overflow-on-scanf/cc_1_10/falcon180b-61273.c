//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount;

void addEntry(char* date, char* entry) {
    strcpy(entries[entryCount].date, date);
    strcpy(entries[entryCount].entry, entry);
    entryCount++;
}

void printEntries() {
    printf("Digital Diary\n");
    printf("=====================\n");
    for(int i=0; i<entryCount; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    int choice;

    time_t now = time(0);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    while(1) {
        printf("1. Add Entry\n2. View Entries\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your entry for %s:\n", date);
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                addEntry(date, entry);
                break;
            case 2:
                printEntries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}