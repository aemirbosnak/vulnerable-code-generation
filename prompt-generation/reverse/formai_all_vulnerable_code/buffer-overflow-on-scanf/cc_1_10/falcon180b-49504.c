//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter time (HH:MM:SS): ");
    scanf("%s", time);
    printf("Enter entry: ");
    scanf("%s", entry);

    strcat(entries[numEntries].date, date);
    strcat(entries[numEntries].date, " ");
    strcat(entries[numEntries].date, time);
    strcat(entries[numEntries].date, ": ");
    strcat(entries[numEntries].date, entry);
    strcat(entries[numEntries].date, "\n");

    numEntries++;
}

void viewEntries() {
    printf("Digital Diary\n\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s", entries[i].date);
    }
}

int main() {
    srand(time(0));

    printf("Welcome to the Digital Diary!\n\n");
    while (1) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}