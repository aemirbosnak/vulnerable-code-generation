//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[50];
    int year;
    int month;
    int day;
    char entry[200];
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
    Entry newEntry;

    printf("Enter name: ");
    scanf("%s", newEntry.name);

    printf("Enter year: ");
    scanf("%d", &newEntry.year);

    printf("Enter month: ");
    scanf("%d", &newEntry.month);

    printf("Enter day: ");
    scanf("%d", &newEntry.day);

    printf("Enter entry: ");
    scanf("%s", newEntry.entry);

    entries[MAX_ENTRIES - 1] = newEntry;
}

void displayEntries() {
    int i;

    printf("Entries:\n");

    for (i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].name[0] != '\0') {
            printf("Name: %s\n", entries[i].name);
            printf("Year: %d\n", entries[i].year);
            printf("Month: %d\n", entries[i].month);
            printf("Day: %d\n", entries[i].day);
            printf("Entry: %s\n", entries[i].entry);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Enter 1 to add an entry, 2 to display entries: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            displayEntries();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}