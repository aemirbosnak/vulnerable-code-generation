//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int numEntries = 0;
Entry entries[MAX_ENTRIES];

void addEntry(char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached\n");
        return;
    }

    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);

    numEntries++;
}

void displayEntries() {
    if (numEntries == 0) {
        printf("No entries found\n");
        return;
    }

    printf("Date\t\tEntry\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t\t%s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntries(char* keyword) {
    if (numEntries == 0) {
        printf("No entries found\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s\t\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char date[10];
    char entry[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(date, 10, "%m/%d/%Y", tm);

    while (1) {
        printf("Enter date (mm/dd/yyyy): ");
        scanf("%s", date);

        printf("Enter entry:\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        addEntry(date, entry);
    }

    return 0;
}