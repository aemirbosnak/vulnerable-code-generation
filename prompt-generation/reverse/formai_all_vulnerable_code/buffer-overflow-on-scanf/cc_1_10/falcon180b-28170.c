//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[10];
    char time[10];
    char entry[100];
} DiaryEntry;

void addEntry(DiaryEntry* entries, int numEntries, char* date, char* time, char* entry) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0 && strcmp(entries[i].time, time) == 0) {
            printf("Entry already exists!\n");
            return;
        }
    }
    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].time, time);
    strcpy(entries[numEntries].entry, entry);
    numEntries++;
}

void viewEntries(DiaryEntry* entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char date[10];
    char time[10];
    char entry[100];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
        printf("Enter time (HH:MM:SS): ");
        scanf("%s", time);
        printf("Enter entry:\n");
        fgets(entry, 100, stdin);
        entry[strcspn(entry, "\n")] = '\0';
        addEntry(entries, numEntries, date, time, entry);
        printf("Do you want to view entries? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            viewEntries(entries, numEntries);
        }
    }

    return 0;
}