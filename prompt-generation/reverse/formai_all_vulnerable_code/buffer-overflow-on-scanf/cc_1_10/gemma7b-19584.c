//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[20];
    char date[20];
    char content[200];
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

    entries[0] = newEntry;
}

void displayEntries() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
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
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("Enter your choice: ");
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