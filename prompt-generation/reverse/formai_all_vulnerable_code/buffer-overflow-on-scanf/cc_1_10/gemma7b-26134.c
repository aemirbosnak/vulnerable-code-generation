//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Entry {
    char title[50];
    char content[200];
    Date date;
} Entry;

Entry entries[100];

void addEntry() {
    Entry newEntry;

    printf("Enter the title of your entry:");
    scanf("%s", newEntry.title);

    printf("Enter the content of your entry:");
    scanf("%s", newEntry.content);

    printf("Enter the date of your entry:");
    scanf("%d", &newEntry.date.day);
    scanf("%d", &newEntry.date.month);
    scanf("%d", &newEntry.date.year);

    entries[0] = newEntry;
}

void displayEntries() {
    for (int i = 0; i < 100; i++) {
        if (entries[i].title[0] != '\0') {
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Date: %d/%d/%d\n", entries[i].date.day, entries[i].date.month, entries[i].date.year);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");

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
                printf("Invalid selection.\n");
        }
    }

    return 0;
}