//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry{
    char date[20];
    char content[500];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if(numEntries == MAX_ENTRIES) {
        printf("Diary is full! Cannot add any more entries.\n");
        return;
    }

    Entry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newEntry.date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf("Enter the content of your entry (max 500 characters):\n");
    getchar();
    fgets(newEntry.content, 500, stdin);
    strcpy(diary[numEntries++].content, newEntry.content);
    printf("Entry added to diary!\n");
}

void showEntries() {
    if(numEntries == 0) {
        printf("No entries to show!\n");
        return;
    }

    printf("Diary Entries:\n");
    for(int i=0; i<numEntries; i++) {
        printf("%s: %s", diary[i].date, diary[i].content);
    }
}

int main() {
    while(1) {
        printf("Choose an option:\n1. Add a new diary entry\n2. Show all diary entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                showEntries();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}