//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[20];
    char date[20];
    char content[100];
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
    Entry newEntry;

    printf("Enter your name: ");
    scanf("%s", newEntry.name);

    printf("Enter the date: ");
    scanf("%s", newEntry.date);

    printf("Enter your entry: ");
    scanf("%s", newEntry.content);

    entries[MAX_ENTRIES - 1] = newEntry;
}

void displayEntries() {
    int i;

    for (i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].name[0] != '\0') {
            printf("Name: %s\n", entries[i].name);
            printf("Date: %s\n", entries[i].date);
            printf("Entry: %s\n", entries[i].content);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter 1 to add an entry, 2 to display entries, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}