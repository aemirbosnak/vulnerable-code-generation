//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char entry[500];
    char tags[200];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    char date[20];
    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    printf("Enter your entry for %s:\n", date);
    fgets(entries[numEntries].entry, 500, stdin);

    printf("Enter tags for this entry (separated by commas):\n");
    scanf("%s", entries[numEntries].tags);

    numEntries++;
}

void viewEntries() {
    printf("Viewing entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
        printf("Tags: %s\n\n", entries[i].tags);
    }
}

void searchEntries() {
    char searchTag[200];
    printf("Enter tag to search for:\n");
    scanf("%s", searchTag);

    int count = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].tags, searchTag)) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
            count++;
        }
    }

    if (count == 0) {
        printf("No entries found with tag '%s'.\n", searchTag);
    }
}

int main() {
    int choice;

    do {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}