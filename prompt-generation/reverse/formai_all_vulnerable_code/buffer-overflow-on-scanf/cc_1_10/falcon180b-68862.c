//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char *date, char *time, char *entry) {
    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].time, time);
    strcpy(entries[numEntries].entry, entry);
    numEntries++;
}

void printEntries() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

int main() {
    char input[100];
    int choice = 0;
    while (choice!= 4) {
        printf("1. Add entry\n2. Print entries\n3. Search entries\n4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", input);
            printf("Enter time (HH:MM:SS): ");
            scanf("%s", input);
            printf("Enter entry: ");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = '\0';
            addEntry(input, input, input);
            printf("Entry added.\n");
            break;
        case 2:
            printEntries();
            break;
        case 3:
            printf("Enter search query: ");
            scanf("%s", input);
            int numResults = 0;
            for (int i = 0; i < numEntries; i++) {
                if (strstr(entries[i].entry, input)!= NULL) {
                    printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
                    numResults++;
                }
            }
            if (numResults == 0) {
                printf("No results found.\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}